import os
import launch
import launch_ros.actions
from ament_index_python.packages import get_package_share_directory
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    velodyne_dir = get_package_share_directory('velodyne')
    velodyne_launch_file = os.path.join(velodyne_dir, 'launch', 'velodyne-all-nodes-VLP16-launch.py')
    velodyne_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            velodyne_launch_file
        )
    )
    scan_merger_dir = get_package_share_directory('laserscan_multi_merger')
    scan_merger_launch_file = os.path.join(scan_merger_dir, 'launch','merge_multi_launch.py')
    scan_merger_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            scan_merger_launch_file
        )
    )
    ld = launch.LaunchDescription()

    ld.add_action(velodyne_launch)
    ld.add_action(scan_merger_launch)
    return ld
