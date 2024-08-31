import sys
import math

import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor

from std_msgs.msg import String
from geometry_msgs.msg import Point
from nav_msgs.msg import Odometry
import time
import math_utils
from rclpy.action import ActionServer
from project_interfaces.action import RequestSensor

NUMBER_OF_BALLOONS = int(sys.argv[1])
NUMBER_OF_SENSORS = int(sys.argv[2])

SENSORS_RANGE = 20

class SimulationManager(Node):

    def __init__(self):

        super().__init__('simulation_manager')

        self.responses = {}
        self.sensor_positions = {}
        self.balloon_positions = {}

        
      
        for i in range(NUMBER_OF_SENSORS):

            self.create_subscription(
                Odometry,
                f'Sensor_{i}/odometry',
                lambda odometry_msg, sensor_id = i: self.store_sensor_position(sensor_id, odometry_msg),
                10
            )

            self.create_subscription(
                String,
                f'Sensor_{i}/tx_data',
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
         self.get_logger().info('$$$$$$$$$$$$ENTRATO IN RESPONSE BALOON$$$$$$$$$$$$$')
         id = msg.data.split(":")[0]
         dati = msg.data.split(":")[1]
         self.get_logger().info('$$$$$$$$$$$$ENTRATO IN RESPONSE BALOON$$$$$$$$$$$$$')
         self.get_logger().info(f"Data for sensor {id} found in cache: {dati}")

         #timestamp = msg.data.split("_")
            
         if self.responses.get(id) is None  : 
           self.responses[id] = dati
         else : 
             if "miss" not in dati : 
                  self.get_logger().info(f"un altro pallone ha già inviato i dati per questo sensore")
             else : 
                 self.responses[id] = msg 
    
                 
                

                 
         


          
          
          



    def store_sensor_position(self, sensor_id, position : Odometry):

        self.sensor_positions[sensor_id] = position.pose.pose.position


    def store_balloon_position(self, balloon_id, position : Odometry):

        self.balloon_positions[balloon_id] = position.pose.pose.position


    def forward_data(self, sensor_id, msg : String):
        for i in range(NUMBER_OF_BALLOONS):
                if math_utils.point_distance(self.sensor_positions[sensor_id], self.balloon_positions[i]) < SENSORS_RANGE:
                    self.balloons_rx[i].publish(msg)
                    
    def forward_data2bs(self, sensor_id):
        # Check if sensor is within range of any balloon
        success = False
        response_msg = String()
        for i in range(NUMBER_OF_BALLOONS):
                if math_utils.point_distance(self.sensor_positions[int(sensor_id)], self.balloon_positions[i]) < SENSORS_RANGE:
                    response_msg = f"bs:{sensor_id}"
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
        c=0
        while self.responses.get(sensor_id) is None  or ("miss" in str(self.responses.get(sensor_id)) ) or c==5:
            c+=1
            if self.responses.get(sensor_id) is None:
                self.get_logger().info('==================================')
                self.get_logger().info('==================================')
                self.get_logger().info(f'ancora nessun dato  per sensore {sensor_id}, rimango in attesa...')
                self.get_logger().info('==================================')
                self.get_logger().info('==================================')
                      
            elif ("miss" in str(self.responses.get(sensor_id))) : 
                 self.get_logger().info('==================================')
                 self.get_logger().info('==================================')
                 self.get_logger().info(f'rilevato cache miss per sensore {sensor_id}, rimango in attesa...')
                 self.get_logger().info('==================================')
                 self.get_logger().info('==================================')
                 
            
            time.sleep(5.0)
        
      
        msg = String()
        msg= self.responses[sensor_id]
        dato = msg
        # timestamp = msg.data.split("_")[2]
        self.get_logger().info('==================================')
        self.get_logger().info('=============HIT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!===================')
        self.get_logger().info('==================================')       
        if success:
            goal_handle.succeed()
            del self.responses[sensor_id]
            result = RequestSensor.Result()
            result.balloons_response = f"Data successfully received from sensor {sensor_id} : {dato}."
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
    
