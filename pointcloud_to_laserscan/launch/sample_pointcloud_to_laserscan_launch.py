from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            name='scanner', default_value='scanner',
            description='Namespace for sample topics'
            ),
        Node(
            package='pointcloud_to_laserscan', executable='pointcloud_to_laserscan_node',
            remappings=[('cloud_in', '/cloud_ltop'), ('scan_points', '/scan_ptol')],
            #remappings=[('cloud_in', [LaunchConfiguration(variable_name='scanner'), '/velodyne_points']),
            #            ('scan_point', [LaunchConfiguration(variable_name='scanner'), '/scan_point'])],
            parameters=[{
                'target_frame': 'base_map_link',
                'transform_tolerance': 0.01,
                'min_height': -0.6,
                'max_height': 2.0,
                'angle_min': -3.14,  # -M_PI/2
                'angle_max': 3.14,  # M_PI/2
                'angle_increment': 0.0087,  # M_PI/360.0
                'scan_time': 0.3333,
                'range_min': 0.1,
                'range_max': 100.0,
                'use_inf': True,
                'inf_epsilon': 1.0
                }],
            name='pointcloud_to_laserscan'
            )
        ])
