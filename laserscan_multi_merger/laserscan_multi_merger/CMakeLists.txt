cmake_minimum_required(VERSION 3.5)
project(laserscan_multi_merger)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(tf2 REQUIRED)
find_package(PCL REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(pcl_ros REQUIRED)
find_package(laser_geometry REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

include_directories(
  include
  include/${PROJECT_NAME}
  include/${EIGEN_INCLUDE_DIRS}
  include/${PCL_INCLUDE_DIRS}
)


add_executable(laserscan_multi_merger_node 
  src/main.cpp
  src/LaserscanMerger.cpp
)

ament_target_dependencies(laserscan_multi_merger_node  
tf2
tf2_ros
PCL
Eigen3
sensor_msgs
rclcpp
std_msgs
pcl_ros
laser_geometry
geometry_msgs
rclcpp_action 
rclcpp_lifecycle
)

install(TARGETS
  laserscan_multi_merger_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY config launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
