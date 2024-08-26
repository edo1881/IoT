import sys
import math

import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor

from std_msgs.msg import String
from geometry_msgs.msg import Point
from nav_msgs.msg import Odometry

import math_utils
from rclpy.action import ActionServer
from project_interfaces.action import RequestSensor

NUMBER_OF_BALLOONS = int(sys.argv[1])
NUMBER_OF_SENSORS = int(sys.argv[2])

SENSORS_RANGE = 40

class SimulationManager(Node):

    def __init__(self):

        super().__init__('simulation_manager')


        self.sensor_positions = {}
        self.balloon_positions = {}

        for i in range(NUMBER_OF_SENSORS):

            self.create_subscription(
                Odometry,
                f'Sensor_{i}/odometry',
                lambda odometry_msg, sensor_id = i: self.store_sensor_position(sensor_id, odometry_msg),
                10
                #self.store_sensor_position
            )

            self.create_subscription(
                String,
                f'Sensor_{i}/tx_data',
                lambda string_msg, sensor_id = i: self.forward_data(sensor_id, string_msg),
                #self.forward_data,
                10
            )
           

        self.balloons_rx = {}

        for i in range(NUMBER_OF_BALLOONS):


            self.create_subscription(
                Odometry,
                f'Balloon_{i}/odometry',
                lambda odometry_msg, balloon_id = i: self.store_balloon_position(balloon_id, odometry_msg),
                10
                #self.store_sensor_position
            )

            self.balloons_rx[i] = self.create_publisher(
                String,
                f'Balloon_{i}/rx_data',
                10
            )

        # Initialize Action Server
        self.action_server = ActionServer(
            self,
            RequestSensor,
            'sensor_request',
            self.handle_sensor_request
        )

    def store_sensor_position(self, sensor_id, position : Odometry):

        self.sensor_positions[sensor_id] = position.pose.pose.position


    def store_balloon_position(self, balloon_id, position : Odometry):

        self.balloon_positions[balloon_id] = position.pose.pose.position


    def forward_data(self, sensor_id, msg : String):

        for i in range(NUMBER_OF_BALLOONS):
            if sensor_id in self.sensor_positions and i in self.balloon_positions:
                
                if math_utils.point_distance(self.sensor_positions[sensor_id], self.balloon_positions[i]) < SENSORS_RANGE:
                    self.balloons_rx[i].publish(msg)
                    
    def forward_data2bs(self, sensor_id):
        # Check if sensor is within range of any balloon
        success = False
        response_msg = String()
        for i in range(NUMBER_OF_BALLOONS):
                if math_utils.point_distance(self.sensor_positions[int(sensor_id)], self.balloon_positions[i]) < SENSORS_RANGE:
                    response_msg = f"bs: Sensor data for {sensor_id}"
                    response_msg_ros = String(data=response_msg)
                    self.balloons_rx[i].publish(response_msg_ros)
                    success = True
                    self.get_logger().info(f"Data sent via Balloon {i} for Sensor {sensor_id}")
                    break
        return success
    
        
    async def handle_sensor_request(self, goal_handle):
        """Handles sensor data requests from the BaseStation."""
        sensor_id = goal_handle.request.bs_request
        self.get_logger().info(f"Received request for sensor {sensor_id}")

        success = self.forward_data2bs(sensor_id)

        if success:
            goal_handle.succeed()
            result = RequestSensor.Result()
            result.balloons_response = f"Data successfully received from sensor {sensor_id}."
            return result
        else:
            goal_handle.abort()
            result = RequestSensor.Result()
            result.balloons_response = f"Failed to retrieve data from sensor {sensor_id}. Sensor may be out of range."
            return result




def main():

    rclpy.init()

    simulationManager= SimulationManager()
    executor = MultiThreadedExecutor()
    executor.add_node(simulationManager)

    executor.spin()

    executor.shutdown()
    simulationManager.destroy_node()

    rclpy.shutdown()
    
