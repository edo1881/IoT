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
       
        lambda_value = 0.04 + (self.id.get_parameter_value().integer_value * 0.001)   
        self.event_scheduler.schedule_event(1/lambda_value, self.simple_publish,args=[lambda_value])
        time.sleep(15)
        self.event_scheduler.schedule_event((1/lambda_value)*2.1,self.execute_patrol_action)

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

    def rotate_to_target_sensor(self, target, eps = 0.5):

        # We compute the angle between the current target position and the target
        # position here
        target_angle = math_utils.angle_between_points(self.position, target)
        angle_to_rotate = target_angle - self.yaw

        # Normalize the angle difference to be within the range [-pi, pi]
        angle_to_rotate = (angle_to_rotate + math.pi) % (2 * math.pi) - math.pi
        #self.get_logger().info(f"in rotate {angle_to_rotate} Rotation: {self.yaw}")
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
            #self.cmd_vel_publisher.publish(move_msg)
            #self.get_logger().info(f"in rotate {angle_to_rotate} Rotation: {self.yaw}")
            #stop_msg = Twist()
            #stop_msg.linear = Vector3(x=0.0, y=0.0, z=0.0)
            #stop_msg.angular = Vector3(x=0.0, y=0.0, z=0.0)
            #self.cmd_vel_publisher.publish(stop_msg)

            # No sleep here. We don't want to miss the angle by sleeping too much. Even 0.1 seconds
            # could make us miss the given epsilon interval

        # When done, send a stop message to be sure that the drone doesn't
        # overshoot its target
        stop_msg = Twist()
        stop_msg.linear = Vector3(x=0.0, y=0.0, z=0.0)
        stop_msg.angular = Vector3(x=0.0, y=0.0, z=0.0)
        self.cmd_vel_publisher.publish(stop_msg)

    def move_to_target_sensor(self, target, eps = 0.5, angle_eps = 0.02):


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

    sensor_controller = SensorController()
    executor.add_node(sensor_controller)

    executor.spin()

    sensor_controller.destroy_node()
    executor.shutdown()
    rclpy.shutdown()
