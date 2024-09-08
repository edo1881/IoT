import random
import time
import math
import threading
import math_utils
import rclpy
import sys
from rclpy.node import Node
from rclpy.action import ActionServer
from rosgraph_msgs.msg import Clock
from sim_utils import EventScheduler 
from rclpy.action.server import ServerGoalHandle
from rclpy.executors import MultiThreadedExecutor
from collections import Counter,OrderedDict
from std_msgs.msg import String
from geometry_msgs.msg import Point, Vector3, Twist
from nav_msgs.msg import Odometry
from project_interfaces.action import Patrol


MIN_ALTITUDE_TO_PERFORM_PATROL = 15
SIZE = int(sys.argv[1])
POLICY = sys.argv[2]
WORLD_NAME = "iot_project_world"

class BalloonController(Node):

    def __init__(self):
        super().__init__("drone_controller")
        self.semaphore = True
        self.lock=threading.Lock()
        self.position = Point(x = 0.0, y = 0.0, z = 0.0)
        self.yaw = 0

        self.stop_msg = Twist()

        self.cmd_vel_publisher = self.create_publisher(
            Twist,
            'cmd_vel',
            10
        )

        self.odometry_subscriber = self.create_subscription(
            Odometry,
            'odometry',
            self.store_position,
            10
        )


        self.rx_data = self.create_subscription(
            String,
            'rx_data',
            self.rx_callback,
            20
        )

        self.patrol_action_server = ActionServer(
            self,
            Patrol,
            'patrol',
            self.execute_patrol_action
        )
        self.bs_publisher = self.create_publisher(
                String,
                'bs',
                10
         )
        self.cache = OrderedDict() # Used for LRU, FIFO, Random
        self.access_counter = Counter()  # Used for LFU
        self.cache_size = SIZE
        self.cache_policy = POLICY
        
        self.event_scheduler = EventScheduler()
        self.clock_topic = self.create_subscription(
            Clock,
            f'/world/{WORLD_NAME}/clock',
            self.event_scheduler.routine,
            10
        )

    def expiration_management(self,sensor_id,id):
        while self.semaphore==False:
            time.sleep(0.1)
        with self.lock:
            self.semaphore=False
            if self.cache.get(sensor_id) is not None and self.cache[sensor_id][0]==id:
                self.get_logger().info(f"sensor_id: {sensor_id} same values, going to delete sent_id: {id}, \
                                       sent_id_cache : {self.cache[sensor_id][0]}")
                del self.cache[sensor_id]
                del self.access_counter[sensor_id]
            self.semaphore=True
        return
    
    def rx_callback(self, msg: String):
        if "bs:" in msg.data:
            self.get_logger().info(f"in bs")
            # Base station is requesting data for a specific sensor
            sensor_id = msg.data.split(":")[1]
            request_id = msg.data.split(":")[2]
            data = self.access_cache(sensor_id)
            #self.get_logger().info(f"========RICEVUTO:{sensor_id} request_id: {request_id}========")
            if data is not None:
                #self.get_logger().info(f"Data for sensor {sensor_id} found in cache: {data}")
                msg = String()
                msg.data = f"{request_id}:{sensor_id}:{data}"
                self.bs_publisher.publish(msg) 

            else:
                #self.get_logger().info(f"Cache miss for sensor {sensor_id}")
                msg = String()
                msg.data = f"{request_id}:{sensor_id}:miss"
                self.bs_publisher.publish(msg) 
    
        elif "Sensor"==msg.data.split(" ")[0]:
            # Sensor is sending data to be stored
            sensor_id=msg.data.split(":")[1].split("_")[0]
            sensor_data=msg.data.split(":")[1].split("_")[1]
            sensor_expiration=int(msg.data.split(":")[1].split("_")[3])
            sent_id=msg.data.split(":")[1].split("_")[2]
            self.get_logger().info(f"id:{sensor_id}, data:{sensor_data}, sent_id: {sent_id}, expiration: {sensor_expiration}")
            self.store_in_cache(sensor_id, sensor_data,sensor_expiration, sent_id)
    def access_cache(self, key):
        if key in self.cache:
            if self.cache_policy == "LRU":
                self.cache.move_to_end(key)  # Update LRU order
                self.get_logger().info(f"LRU access: Moved {key} to the end of the cache.")
            elif self.cache_policy == "LFU":
                self.access_counter[key] += 1  # Increase LFU access count
                self.get_logger().info(f"LFU access: Increased access count for {key}.")
            return self.cache[key]
        self.get_logger().info(f"Cache miss for {key}.")
        return None  # Cache miss

    def store_in_cache(self, key, data , scadenza, sent_id):
        if len(self.cache) == self.cache_size:
            self.evict_cache()
        
        self.cache[key] = [sent_id,data,scadenza] 
     
        self.event_scheduler.schedule_event(
                scadenza,
                self.expiration_management,
                repeat=False,
                args=[key,sent_id]
        )
    

    def evict_cache(self):
        if self.cache_policy == "FIFO" or self.cache_policy == "LRU" or \
            (self.cache_policy == "LFU" and len(self.access_counter)==0):
            self.cache.popitem(last=False)  # Evict the first item (FIFO) or the least recently used item (LRU)
            #self.get_logger().info(f"Evicted {evicted_key}: {evicted_value} from cache using {self.cache_policy} policy.")
        elif self.cache_policy == "LFU":
            lfu_key = min(self.access_counter, key=self.access_counter.get)
            self.cache[lfu_key]
            del self.cache[lfu_key]
            del self.access_counter[lfu_key]
            #self.get_logger().info(f"Evicted {lfu_key}: {evicted_value} from cache using LFU policy.")
        elif self.cache_policy == "Random":
            random_key = random.choice(list(self.cache.keys()))
            self.cache[random_key]
            del self.cache[random_key]
            #self.get_logger().info(f"Evicted {random_key}: {evicted_value} from cache using Random policy.")

    def display_cache(self):
        self.get_logger().info(f"Cache content ({self.cache_policy}): {list(self.cache.keys())}")

    def store_position(self, odometry_msg : Odometry):

        self.position = odometry_msg.pose.pose.position
        self.yaw = math_utils.get_yaw(
            odometry_msg.pose.pose.orientation.x,
            odometry_msg.pose.pose.orientation.y,
            odometry_msg.pose.pose.orientation.z,
            odometry_msg.pose.pose.orientation.w
        )

    def execute_patrol_action(self, goal : ServerGoalHandle):


        command_goal : Patrol.Goal = goal.request

        #self.get_logger().info(f"Action requested. Performing initial flight")
        self.fly_to_altitude(MIN_ALTITUDE_TO_PERFORM_PATROL)
        goal.succeed()

        result =  Patrol.Result()
        result.result = "Movement completed"

        return result

    def fly_to_altitude(self, altitude):

        # Instantiate the move_up message
        move_up = Twist()
        move_up.linear = Vector3(x=0.0, y=0.0, z=1.0)
        move_up.angular = Vector3(x=0.0, y=0.0, z=0.0)

        self.cmd_vel_publisher.publish(move_up)

        # Wait for the drone to reach the desired altitude
        while(self.position.z < altitude):
            time.sleep(0.1)

        # Stop movement after the altitude has been reached
        stop_mov = Twist()
        stop_mov.linear = Vector3(x=0.0, y=0.0, z=0.0)
        stop_mov.angular = Vector3(x=0.0, y=0.0, z=0.0)
        self.cmd_vel_publisher.publish(stop_mov)
        
def main():
    
    rclpy.init()
    executor = MultiThreadedExecutor()

    drone_controller = BalloonController()
    executor.add_node(drone_controller)

    executor.spin()

    drone_controller.destroy_node()
    executor.shutdown()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
