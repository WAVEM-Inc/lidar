#ifndef CARNAVI_LIDAR__INCLUDE__CONSTANTS_SETTING__HPP_
#define CARNAVI_LIDAR__INCLUDE__CONSTANTS_SETTING__HPP_
#include <iostream>
namespace Constants{
    class Setting{
        public :
            const int port_;
            const std::string multicast_group_ip_;
            const std::string lidar_ip_;
            Setting(int port, std::string multicast_group_ip,std::string lidar_ip):
                port_(port),multicast_group_ip_(multicast_group_ip),lidar_ip_(lidar_ip){
            }           
    };
    class Receiver{
        public :
            const int scan_pub_queue_size_;
            const int scan_hz_;
            const float scan_increment_;
            const float scan_angle_max_;
            const float scan_angle_min_;
            const float scan_range_max_;
            const float scan_range_min_;
            const std::string topic_ch0_;
            const std::string topic_ch1_;
            const std::string topic_frame_;
            Receiver(int scan_pub_queue_size, int scan_hz,float scan_increment,float scan_angle_max,float scan_angle_min,float scan_range_max,float scan_range_min, std::string topic_ch0, std::string topic_ch1,std::string topic_frame): 
                scan_pub_queue_size_(scan_pub_queue_size), scan_hz_(scan_hz),
                scan_increment_(scan_increment), scan_angle_max_(scan_angle_max),
                scan_angle_min_(scan_angle_min), scan_range_max_(scan_range_max),scan_range_min_(scan_angle_min),
                topic_ch0_(topic_ch0),topic_ch1_(topic_ch1),topic_frame_(topic_frame){
            }           
    };
}

#endif