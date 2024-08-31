import sys
import rclpy
from rclpy.node import Node
from rclpy.timer import Timer
from rclpy.executors import MultiThreadedExecutor
from std_msgs.msg import String
from nav_msgs.msg import Odometry
from rosgraph_msgs.msg import Clock  # Import the Clock message type
import time
import random
from rclpy.action import ActionClient
from sim_utils import EventScheduler
from project_interfaces.action import RequestSensor  # Custom action definition
NUMBER_OF_BALLOONS = int(sys.argv[1])
NUMBER_OF_SENSORS = int(sys.argv[2])
WORLD_NAME = "iot_project_world"
class BaseStation(Node):
    def __init__(self):
        super().__init__('simulation_manager')
        self.id = 0
	    # Initialize action client for requesting sensor data
        self._action_client = ActionClient(self, RequestSensor, 'sensor_request')
        
        self.sensor_data = {}  # Stores received sensor data
        self.missing_data = {}  # Keeps track of missing data requests
        self.hit_data = {}

        # Optionally subscribe to the odometry topic if needed
        self.create_subscription(
            Odometry,
            'base_station/odometry',
            self.store_position,
            10
        )
        # Example: Assume data format is "sensor_id:data"'''
        # Initialize EventScheduler
        time.sleep(20)
        self.scheduler = EventScheduler()
        # Subscribe to the simulation clock to trigger the event scheduler
        self.clock_subscription = self.create_subscription(
            Clock,
            f'/world/{WORLD_NAME}/clock',  # Use the correct clock topic
            self.scheduler.routine,
            10
        )
        self.schedule_sensor_requests()

    def schedule_sensor_requests(self):
        """
        Schedule requests to each sensor using Poisson inter-arrival times.
        """
        for sensor_id in range(NUMBER_OF_SENSORS):
            lambda_value = self.get_lambda_for_sensor(sensor_id)
            self.scheduler.schedule_event(
                1/lambda_value,
                self.request_sensor_data,
                repeat=True,
                args=[sensor_id]
            )

    def request_sensor_data(self, sensor_id):
        """
        Send a request to the SimulationManager to retrieve data from a specific sensor.
        """
        self.get_logger().info(f"Requesting data from sensor {sensor_id}:{self.id}")

        goal_msg = RequestSensor.Goal()
        goal_msg.bs_request = f"{sensor_id}:{self.id}"
        self._action_client.wait_for_server()
        send_goal_future = self._action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )
        self.id+=1
        send_goal_future.add_done_callback(self.goal_response_callback)

    
    def get_lambda_for_sensor(self, sensor_id):
        """
        Define lambda values for different sensors based on their characteristics.
        """
        # Example: You could have different lambda values for different sensors
        # For now, we'll just use a fixed lambda value for all sensors
        return 0.03 + (sensor_id * 0.003)   # Example, customize this as need
        
    def store_position(self, msg: Odometry):
        """
        Store or use the base station's position if needed.
        """
        position = msg.pose.pose.position
        self.get_logger().info(f"Base station position: {position.x}, {position.y}, {position.z}")

   
    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected.')
            return

        self.get_logger().info('Goal accepted.')
        self.result_callback(future)

    def result_callback(self, future):
        goal_handle = future.result()
        result = goal_handle.get_result().result
        if True:
            self.get_logger().info('============ BASE STATION ===================')
            self.get_logger().info(f"Data received successfully for sensor {result.balloons_response}")
            self.get_logger().info('==================================')

            # Process the data here if necessary
        else:
            self.get_logger().info(f"Data request failed for sensor {result.balloons_response}")
            # Handle missing data

    def feedback_callback(self, feedback_msg):
        self.get_logger().info(f"Feedback received: {feedback_msg.feedback.feed}")

    

def main():
    rclpy.init()

    base_station = BaseStation()
    executor = MultiThreadedExecutor()
    executor.add_node(base_station)

    executor.spin()

    executor.shutdown()
    base_station.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
