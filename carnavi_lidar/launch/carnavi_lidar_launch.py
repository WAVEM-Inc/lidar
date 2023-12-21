
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument

from launch.substitutions import LaunchConfiguration
from launch.substitutions import ThisLaunchFileDir
from launch_ros.actions import Node


def generate_launch_description():
    carnavi_param_dir = LaunchConfiguration(
        'carnavi_lidar',
        default=os.path.join(
            get_package_share_directory('carnavi_lidar'),
            'param',
            'VL-R2.yaml'))
    #test = '/home/oem/colcon_ws/src/lidar/carnavi_lidar/install/carnavi_lidar/share/carnavi_lidar/param/VL-R2.yaml'
    return LaunchDescription([
        DeclareLaunchArgument(
            'carnavi_lidar',
            default_value=carnavi_param_dir,
            description='Full path to turtlebot3 parameter file to load'),

        Node(
            package='carnavi_lidar',
            executable='carnavi_lidar_node',
            parameters=[carnavi_param_dir],
            output='screen'),
    ])
