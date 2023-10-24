#include<iostream>
#include"rclcpp/rclcpp.hpp"
#include"lidar_manager.hpp"
#include <memory>
int main(int argc,char** argv){
    rclcpp::init(argc,argv);
    std::shared_ptr<CARNAVI::LidarManager> carnavi=std::make_shared<CARNAVI::LidarManager>();
    carnavi->start_lidar();
    rclcpp::shutdown();
    return 0;
}