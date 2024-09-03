import sys
import math

import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from collections import defaultdict
from std_msgs.msg import String
from geometry_msgs.msg import Point
from nav_msgs.msg import Odometry
import time
import math_utils
from rclpy.action import ActionServer
from project_interfaces.action import RequestSensor

NUMBER_OF_BALLOONS = int(sys.argv[1])
NUMBER_OF_SENSORS = int(sys.argv[2])

SENSORS_RANGE = 40

class SimulationManager(Node):

    def __init__(self):

        super().__init__('simulation_manager')

        self.responses = defaultdict(list)
        self.sensor_positions = {}
        self.balloon_positions = {}
        self.balloon_per_sensor= {}
      
        for i in range(NUMBER_OF_SENSORS):

            self.create_subscription(
                Odometry,
                f'ActiveSensor_{i}/odometry',
                lambda odometry_msg, sensor_id = i: self.store_sensor_position(sensor_id, odometry_msg),
                10
            )

            self.create_subscription(
                String,
                f'ActiveSensor_{i}/tx_data',
                lambda string_msg, sensor_id = i: self.forward_data(sensor_id, string_msg),
                10
            )
           

        self.balloons_rx = {}

        for i in range(NUMBER_OF_BALLOONS):
            self.create_subscription(
                String,
                f'Balloon_{i}/bs',
                self.response_balloon,
                10
            )


            self.create_subscription(
                Odometry,
                f'Balloon_{i}/odometry',
                lambda odometry_msg, balloon_id = i: self.store_balloon_position(balloon_id, odometry_msg),
                10
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
    

    def response_balloon(self, msg):
         id = msg.data.split(":")[0]
         sensor_id =msg.data.split(":")[1]
         dati = msg.data.split(":")[2]
         self.responses[id].append(dati)


    def store_sensor_position(self, sensor_id, position : Odometry):
        self.sensor_positions[sensor_id] = position.pose.pose.position


    def store_balloon_position(self, balloon_id, position : Odometry):

        self.balloon_positions[balloon_id] = position.pose.pose.position


    def forward_data(self, sensor_id, msg : String):
        for i in range(NUMBER_OF_BALLOONS):
                if math_utils.point_distance(self.sensor_positions[sensor_id], self.balloon_positions[i]) < SENSORS_RANGE:
                    self.balloons_rx[i].publish(msg)
                    
    def forward_data2bs(self, sensor_id,request_id):
        # Check if sensor is within range of any balloon
        response_msg = String()
        self.balloon_per_sensor[request_id] = 0
        for i in range(NUMBER_OF_BALLOONS):
                if math_utils.point_distance(self.sensor_positions[int(sensor_id)], self.balloon_positions[i]) < SENSORS_RANGE:
                    self.balloon_per_sensor[request_id] += 1
                    response_msg = f"bs:{sensor_id}:{request_id}"
                    response_msg_ros = String(data=response_msg)
                    self.balloons_rx[i].publish(response_msg_ros)
                    self.get_logger().info(f"Request sent via Balloon {i} for Sensor {sensor_id}")
    
        
    async def handle_sensor_request(self, goal_handle):
        """Handles sensor data requests from the BaseStation."""
        sensor_id = goal_handle.request.bs_request.split(":")[0]
        request_id = goal_handle.request.bs_request.split(":")[1]
        self.get_logger().info(f"Received request for sensor {sensor_id},rid:{request_id}")

        self.forward_data2bs(sensor_id,request_id)
        c=0
        while (self.responses.get(request_id) is None or any("miss" in str(value) for value in self.responses.get(request_id, [])))  and (self.responses.get(request_id) is None or len(self.responses.get(request_id)) < self.balloon_per_sensor[request_id]) and c<=7:
            c+=1
            time.sleep(6.0)
        test= str(any("miss" in str(value) for value in self.responses.get(request_id, [])))
        msg = String()
        msg= " ".join(val for val in self.responses.get(request_id, []))
        dato = msg
        # timestamp = msg.data.split("_")[2]
        self.get_logger().info('==================================')
        self.get_logger().info(f'=============USCITO: {test} msg: {msg} request_id:{request_id} sensor:{sensor_id}!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!===================')
        self.get_logger().info('==================================')       
        goal_handle.succeed()
        result = RequestSensor.Result()
        result.balloons_response = f"Data successfully received from sensor {sensor_id} : {dato}."
        #del self.responses[request_id]
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
    
