#ifndef VEL_LISTENER_HPP__
#define VEL_LISTENER_HPP__
#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
using LidarMSG = sensor_msgs::msg::LaserScan;
class VelodyneListener : public rclcpp::Node{
    private :
        rclcpp::Subscription<LidarMSG>::SharedPtr sub_scan_;
        void scan_callback(const std::shared_ptr<LidarMSG> scan);
    public :
        VelodyneListener();

};
#endif
