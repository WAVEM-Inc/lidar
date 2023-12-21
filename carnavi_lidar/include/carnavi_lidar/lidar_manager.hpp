#ifndef CARNAVI_LIDAR__INCLUDE__LIDAR_MANAGER__HPP_
#define CARNAVI_LIDAR__INCLUDE__LIDAR_MANAGER__HPP_
#include "rclcpp/rclcpp.hpp"
#include "lidar_setting.hpp"
#include "lidar_receiver.hpp"
#include "setting/constants.hpp"
namespace CARNAVI{
    class LidarManager: public rclcpp::Node{
        public : 
            LidarManager();
            void start_lidar();
        private : 
            std::unique_ptr<Constants::Setting> constants_setting_;
            std::unique_ptr<Constants::Receiver> constants_receiver_;
    };

}
#endif