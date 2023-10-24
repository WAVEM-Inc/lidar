#ifndef CARNAVI_LIDAR__INCLUDE__LIDAR_RECEIVER__HPP_
#define CARNAVI_LIDAR__INCLUDE__LIDAR_RECEIVER__HPP_
#include <iostream>
#include <vector>
#include "setting/df_receiver.hpp"
#include "setting/constants.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <memory>
namespace CARNAVI{
    class LidarReceiver: rclcpp::Node{
        public :
            LidarReceiver();
            LidarReceiver(std::unique_ptr<Constants::Receiver> constants_receiver);
            virtual ~LidarReceiver();
            int receiver_run();
            void receiver_setting(int sd);
        private : 
            int sd_;
            sensor_msgs::msg::LaserScan lidar_setting();
            std::unique_ptr<Constants::Receiver> constants_receiver_;
            void* memmem(const void *buf, size_t buflen,const void *pattern, size_t len);
            float degree_to_radian(float degree);


    };
}
#endif
