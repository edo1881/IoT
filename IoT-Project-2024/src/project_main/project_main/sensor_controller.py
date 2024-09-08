from threading import Thread
import time
import rclpy
import random
import math
import math_utils
from rclpy.node import Node
from geometry_msgs.msg import Point,Vector3,Twist
from nav_msgs.msg import Odometry
from rclpy.executors import MultiThreadedExecutor

from std_msgs.msg import String
from rosgraph_msgs.msg import Clock

from sim_utils import EventScheduler


WORLD_NAME = "iot_project_world"

class SensorController(Node):

    def __init__(self):
        super().__init__('sensor_controller')
        self.sent_id=0
        self.x_limit=100
        self.y_limit=100
        self.position = Point(x = 0.0, y = 0.0, z = 0.0)
        self.yaw = 0
        self.stop_msg = Twist()
        self.tx_topic = self.create_publisher(
            String,
            'tx_data',
            10
        )
        self.cmd_vel_publisher = self.create_publisher(
            Twist,
            'cmd_vel',
            10
        )

        self.odometry_subscriber = self.create_subscription(
            Odometry,
            'odometry',
            self.store_position_sensor,
            10
        )
        self.id = self.declare_parameter('id', -1)

        self.generated_data = 0


        self.event_scheduler = EventScheduler()
        self.clock_topic = self.create_subscription(
            Clock,
            f'/world/{WORLD_NAME}/clock',
            self.event_scheduler.routine,
            10
        )
       
        lambda_value = 0.06 + (self.id.get_parameter_value().integer_value * 0.001)   
        self.event_scheduler.schedule_event(1/lambda_value, self.simple_publish,args=[lambda_value])
        Thread(self.event_scheduler.schedule_event((1/lambda_value)*2.1,self.execute_patrol_action)).start()

    def simple_publish(self,lambda_value):
        id = self.id.get_parameter_value().integer_value
        msg = String()
        exp=random.randint(math.floor(0.7*(1/lambda_value)),math.floor(3*(1/lambda_value)))
        msg.data = f"Sensor data:{id}_{self.generate_data()}_{self.sent_id}_{exp}"
        self.tx_topic.publish(msg) 
        self.sent_id+=1

    def generate_data(self):
        self.generated_data += 1
        return self.generated_data
    
    def store_position_sensor(self, odometry_msg: Odometry):
        self.position = odometry_msg.pose.pose.position
        self.yaw = math_utils.get_yaw(
            odometry_msg.pose.pose.orientation.x,
            odometry_msg.pose.pose.orientation.y,
            odometry_msg.pose.pose.orientation.z,
            odometry_msg.pose.pose.orientation.w
        )
        if self.position.x > 45 or self.position.x < -45 or self.position.y > 45 or self.position.y < -45:
             stop_msg = Twist()
             stop_msg.linear = Vector3(x=-1.0, y=0.0, z=0.0)
             stop_msg.angular = Vector3(x=0.0, y=0.0, z=0.0)
             self.cmd_vel_publisher.publish(stop_msg)
             time.sleep(4)
             stop_msg = Twist()
             stop_msg.linear = Vector3(x=0.0, y=0.0, z=0.0)
             stop_msg.angular = Vector3(x=0.0, y=0.0, z=0.0)
             self.cmd_vel_publisher.publish(stop_msg)

    def execute_patrol_action(self):
        id = self.id.get_parameter_value().integer_value
        target = float(random.randint(-1,1))
        stop_msg = Twist()
        stop_msg.linear = Vector3(x=target, y=0.0, z=0.0)
        stop_msg.angular = Vector3(x=0.0, y=0.0, z=0.0)
        self.cmd_vel_publisher.publish(stop_msg)
        time.sleep(2)
        stop_msg = Twist()
        stop_msg.linear = Vector3(x=0.0, y=0.0, z=0.0)
        stop_msg.angular = Vector3(x=0.0, y=0.0, z=0.5)
        self.cmd_vel_publisher.publish(stop_msg)
        time.sleep(1)
        stop_msg = Twist()
        stop_msg.linear = Vector3(x=0.0, y=0.0, z=0.0)
        stop_msg.angular = Vector3(x=0.0, y=0.0, z=0.0)
        self.cmd_vel_publisher.publish(stop_msg)


def main():
    
    rclpy.init()
    executor = MultiThreadedExecutor()

    sensor_controller = SensorController()
    executor.add_node(sensor_controller)

    executor.spin()

    sensor_controller.destroy_node()
    executor.shutdown()
    rclpy.shutdown()
