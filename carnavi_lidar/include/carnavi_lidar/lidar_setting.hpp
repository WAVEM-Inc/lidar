#ifndef CARNAVI_LIDAR__INCLUDE__LIDAR_SETTING__HPP_
#define CARNAVI_LIDAR__INCLUDE__LIDAR_SETTING__HPP_

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include <memory>
#include "setting/constants.hpp"
namespace CARNAVI{
    class LidarSetting{
        public :
            LidarSetting();
            LidarSetting(std::unique_ptr<Constants::Setting> constants_setting);
            int setting_check();
            int get_lidar_setting();
        private : 
	        int sd_;
            std::unique_ptr<Constants::Setting> constants_setting_;
            int setting();
            int multicast_setting();
    };
}
#endif