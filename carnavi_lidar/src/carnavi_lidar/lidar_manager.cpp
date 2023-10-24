
#include "lidar_manager.hpp"
#include <memory>
CARNAVI::LidarManager::LidarManager():Node("carnavi_lidar_node"){
    LidarSetting lidar_setting;
    rclcpp::Parameter parameter;

    std::string lidar_ip;
    std::string multicast_group_ip;
    int port;
    this->declare_parameter<std::string>("lidar_ip", "192.168.123.5");
    this->declare_parameter<std::string>("multicast_group_ip", "224.0.0.5");
    this->declare_parameter<int>("port",5000);
    //
    this->declare_parameter<std::string>("topic.ch0","/scan/ch00");
    this->declare_parameter<std::string>("topic.ch1","/scan/ch01");
    this->declare_parameter<std::string>("topic.frame","/base_laser_link");
    this->declare_parameter<int>("scan.pub_queue_size",10);
    this->declare_parameter<int>("scan.hz",10);
    this->declare_parameter<float>("scan.increment",0.1);
    this->declare_parameter<float>("scan.angle_max",30.0);
    this->declare_parameter<float>("scan.angle_min",-30.0);
    this->declare_parameter<float>("scan.range_max",30.0);
    this->declare_parameter<float>("scan.range_min",0.3);
    if (this->get_parameter("lidar_ip", lidar_ip)) {
        std::cout<<lidar_ip<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'lidar_ip' not found.");
    }
    if (this->get_parameter("multicast_group_ip", multicast_group_ip)) {
        std::cout<<multicast_group_ip<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'multicast_group_ip' not found.");
    }
    if (this->get_parameter("port", port)) {
        std::cout<<port<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'port' not found.");
    }
    constants_setting_= std::make_unique<Constants::Setting>(port,multicast_group_ip,lidar_ip);
    std::string ch0,ch1,frame;
    int pub_queue_size,hz;
    double increment, angle_max,angle_min,range_max,range_min;
    if (this->get_parameter("topic.ch0", ch0)) {
        std::cout<<ch0<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'ch0' not found.");
    }
    if (this->get_parameter("topic.ch1", ch1)) {
        std::cout<<ch1<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'ch1' not found.");
    }
    if (this->get_parameter("topic.frame", frame)) {
        std::cout<<frame<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'frame' not found.");
    }
    if (this->get_parameter("scan.pub_queue_size", pub_queue_size)) {
        std::cout<<pub_queue_size<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'pub_queue_size' not found.");
    }
    if (this->get_parameter("scan.pub_queue_size", pub_queue_size)) {
        std::cout<<pub_queue_size<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'pub_queue_size' not found.");
    }
    if (this->get_parameter("scan.hz", hz)) {
        std::cout<<hz<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'hz' not found.");
    }
    if (this->get_parameter("scan.increment", increment)) {
        std::cout<<increment<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'increment' not found.");
    }
    if (this->get_parameter("scan.angle_max", angle_max)) {
        std::cout<<angle_max<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'angle_max' not found.");
    }
    if (this->get_parameter("scan.angle_min", angle_min)) {
        std::cout<<angle_min<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'angle_min' not found.");
    }
    if (this->get_parameter("scan.range_max", range_max)) {
        std::cout<<range_max<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'range_max' not found.");
    }
    if (this->get_parameter("scan.range_min", range_min)) {
        std::cout<<range_min<<std::endl;
    } else {
        RCLCPP_WARN(this->get_logger(), "Parameter 'range_min' not found.");
    }
    constants_receiver_= std::make_unique<Constants::Receiver>(pub_queue_size,hz,increment,angle_max,angle_min,range_max,range_min,ch0,ch1,frame);
}
void CARNAVI::LidarManager::start_lidar(){
    std::shared_ptr<CARNAVI::LidarSetting> lidar_setting=std::make_shared<CARNAVI::LidarSetting>(std::move(constants_setting_));
    std::shared_ptr<CARNAVI::LidarReceiver> lidar_reciver=std::make_shared<CARNAVI::LidarReceiver>(std::move(constants_receiver_));
    lidar_setting->setting_check();
    lidar_reciver->receiver_setting(lidar_setting->get_lidar_setting());
    lidar_reciver->receiver_run();
}