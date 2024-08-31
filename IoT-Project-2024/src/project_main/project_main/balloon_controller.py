import time
import math

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rosgraph_msgs.msg import Clock
from sim_utils import EventScheduler 
from rclpy.action.server import ServerGoalHandle
from rclpy.executors import MultiThreadedExecutor
from collections import Counter
from std_msgs.msg import String
from geometry_msgs.msg import Point, Vector3, Twist
from nav_msgs.msg import Odometry

import math_utils
from project_interfaces.action import Patrol


MIN_ALTITUDE_TO_PERFORM_PATROL = 15
SIZE = 10

WORLD_NAME = "iot_project_world"

class BalloonController(Node):

    def __init__(self):
        super().__init__("drone_controller")

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
        self.cache = {}  # Used for LRU, FIFO, Random
        self.access_counter = Counter()  # Used for LFU
        self.cache_size = SIZE
        self.cache_policy = "Random"  # Change to "LFU", "FIFO", or "Random"
        
        self.event_scheduler = EventScheduler()
        self.clock_topic = self.create_subscription(
            Clock,
            f'/world/{WORLD_NAME}/clock',
            self.event_scheduler.routine,
            10
        )

    def expiration_management(self, sensor_id):
        self.get_logger().info(f"eliminazione dati id : {sensor_id}")
        del self.cache[sensor_id]
        del self.access_counter[sensor_id]

        return
    def rx_callback(self, msg: String):
        if "bs:" in msg.data:
            self.get_logger().info(f"in bs")
            # Base station is requesting data for a specific sensor
            sensor_id = msg.data.split(":")[1]
            data = self.access_cache(sensor_id)
            if data is not None:
                self.get_logger().info(f"Data for sensor {sensor_id} found in cache: {data}")
                msg = String()
                msg.data = f"{sensor_id}:{data}"
                self.get_logger().info(f"AOOOOOOOOO STO INVIANDO ==============")
                
                self.bs_publisher.publish(msg) 


            else:
                self.get_logger().info(f"Cache miss for sensor {sensor_id}")
                msg = String()
                msg.data = f"{sensor_id}:miss"
                self.bs_publisher.publish(msg) 
                # Handle cache miss, e.g., by fetching data from another source
        elif "Sensor"==msg.data.split(" ")[0]:
            # Sensor is sending data to be stored
            sensor_id=msg.data.split(":")[1].split("_")[0]
            sensor_data=msg.data.split(":")[1].split("_")[1]
            sensor_expiration=int(msg.data.split(":")[1].split("_")[2])


            self.get_logger().info(f"id:{sensor_id},data:{sensor_data},expiration: {sensor_expiration}")
            self.store_in_cache(sensor_id, sensor_data,sensor_expiration)
            self.get_logger().info(f"Data for sensor {sensor_id} stored in cache.")
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

    def store_in_cache(self, key, data , scadenza):
        if len(self.cache) == self.cache_size:
            self.evict_cache()
        self.cache[key] = data
        '''self.get_logger().info(f"Stored {key}: {data} in cache. Current cache size: {len(self.cache)}.")
        self.event_scheduler.schedule_event(
                scadenza,
                self.expiration_management,
                repeat=False,
                args=[key]
        )'''
    

    def evict_cache(self):
        if self.cache_policy == "FIFO" or self.cache_policy == "LRU":
            evicted_key, evicted_value = self.cache.popitem(last=False)  # Evict the first item (FIFO) or the least recently used item (LRU)
            self.get_logger().info(f"Evicted {evicted_key}: {evicted_value} from cache using {self.cache_policy} policy.")
        elif self.cache_policy == "LFU":
            lfu_key = min(self.access_counter, key=self.access_counter.get)
            evicted_value = self.cache[lfu_key]
            del self.cache[lfu_key]
            del self.access_counter[lfu_key]
            self.get_logger().info(f"Evicted {lfu_key}: {evicted_value} from cache using LFU policy.")
        elif self.cache_policy == "Random":
            random_key = random.choice(list(self.cache.keys()))
            evicted_value = self.cache[random_key]
            del self.cache[random_key]
            self.get_logger().info(f"Evicted {random_key}: {evicted_value} from cache using Random policy.")

    def display_cache(self):
        self.get_logger().info(f"Cache content ({self.cache_policy}): {list(self.cache.keys())}")

    def store_position(self, odometry_msg: Odometry):
        self.position = odometry_msg.pose.pose.position
        self.yaw = math_utils.get_yaw(
            odometry_msg.pose.pose.orientation.x,
            odometry_msg.pose.pose.orientation.y,
            odometry_msg.pose.pose.orientation.z,
            odometry_msg.pose.pose.orientation.w
        )

    def store_position(self, odometry_msg : Odometry):

        self.position = odometry_msg.pose.pose.position
        self.yaw = math_utils.get_yaw(
            odometry_msg.pose.pose.orientation.x,
            odometry_msg.pose.pose.orientation.y,
            odometry_msg.pose.pose.orientation.z,
            odometry_msg.pose.pose.orientation.w
        )
        #self.get_logger().info(f"Storing position {self.drone_position}")

    def execute_patrol_action(self, goal : ServerGoalHandle):


        command_goal : Patrol.Goal = goal.request

        self.get_logger().info(f"Action requested. Performing movement to targets:\n\t{command_goal.targets}")

        self.fly_to_altitude(MIN_ALTITUDE_TO_PERFORM_PATROL)


        targets_patrolled = 0
        
        for target in command_goal.targets:
                
            self.rotate_to_target(target)
            self.move_to_target(target)

            self.get_logger().info(f"Movement to target {targets_patrolled} completed!")
            targets_patrolled += 1
        
        
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

    def rotate_to_target(self, target, eps = 0.5):

        # We compute the angle between the current target position and the target
        # position here
        target_angle = math_utils.angle_between_points(self.position, target)
        angle_to_rotate = target_angle - self.yaw

        # Normalize the angle difference to be within the range [-pi, pi]
        angle_to_rotate = (angle_to_rotate + math.pi) % (2 * math.pi) - math.pi

        # And then assign the direction of the rotation correctly
        rotation_dir = 1 if angle_to_rotate < 0 else -1
        
        # Prepare the cmd_vel message
        move_msg = Twist()
        move_msg.linear = Vector3(x=0.0, y=0.0, z=0.0)
        move_msg.angular = Vector3(x=0.0, y=0.0, z = 0.5 * rotation_dir)
        self.cmd_vel_publisher.publish(move_msg)

        # Publish the message until the correct rotation is reached (accounting for some eps error)
        # Note that here the eps also helps us stop the drone and not overshoot the target, as
        # the drone will keep moving for a while after it receives a stop message
        # Also note that rotating the drone too fast will make it loose altitude.
        # You can account for that by also giving some z linear speed to the rotation movement.
        while abs(angle_to_rotate) > eps:
            angle_to_rotate = target_angle - self.yaw

            # self.get_logger().info(f"Rotation: {self.yaw}")
            # No sleep here. We don't want to miss the angle by sleeping too much. Even 0.1 seconds
            # could make us miss the given epsilon interval

        # When done, send a stop message to be sure that the drone doesn't
        # overshoot its target
        stop_msg = Twist()
        stop_msg.linear = Vector3(x=0.0, y=0.0, z=0.0)
        stop_msg.angular = Vector3(x=0.0, y=0.0, z=0.0)
        self.cmd_vel_publisher.publish(stop_msg)

    def move_to_target(self, target, eps = 0.5, angle_eps = 0.02):


        # Save the target position and compute the distance
        distance = math_utils.point_distance(self.position, target)

        # Keep publishing movement while the distance is greater than the given EPS
        while (distance > eps):

            # Compute the move vector with the given position and target
            mv = math_utils.move_vector(self.position, target)

            twist_msg = Twist()
            twist_msg.linear.x = mv[0]
            twist_msg.linear.z = mv[1]

            # Check if Balloon is still facing the target correctly, otherwise add angular
            # velocity to the Twist msg
            target_angle = math_utils.angle_between_points(self.position, target)

            if not (target_angle - angle_eps < self.yaw < target_angle + angle_eps):
                angle_diff = (self.yaw - target_angle)
                twist_msg.angular = Vector3(x=0.0, y=0.0, z=math.sin(angle_diff))


            # Publish msg
            self.cmd_vel_publisher.publish(twist_msg)

            # Update position and distance after finishing
            distance = math_utils.point_distance(self.position, target)


        # After reaching the target, publish a stop msg
        self.cmd_vel_publisher.publish(self.stop_msg)


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
