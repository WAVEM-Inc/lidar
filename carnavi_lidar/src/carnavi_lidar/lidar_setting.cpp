#include"lidar_setting.hpp"
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <utility> 
#include <memory>
CARNAVI::LidarSetting::LidarSetting(){
    
}
CARNAVI::LidarSetting::LidarSetting(std::unique_ptr<Constants::Setting> constants_setting):constants_setting_(std::move(constants_setting)){
	
}

int CARNAVI::LidarSetting::setting_check(){
    return (setting()==-1 || multicast_setting()==-1)? -1 : 0;
}
int CARNAVI::LidarSetting::setting(){
    struct sockaddr_in localSock;
    sd_ = socket(AF_INET, SOCK_DGRAM,0);
    if(sd_<0){
        perror("opening datagram socket");
		return -1;
    }
    memset((char*) &localSock,0,sizeof(localSock));
	localSock.sin_family = AF_INET;
	localSock.sin_port = htons(constants_setting_->port_);
	localSock.sin_addr.s_addr  = INADDR_ANY;
    if (bind(sd_, (struct sockaddr*)&localSock, sizeof(localSock))) {
		perror("binding datagram socket");
		close(sd_);
		return -1;
	}
    return 0;
}

int CARNAVI::LidarSetting::multicast_setting(){
    struct ip_mreq group;
    group.imr_multiaddr.s_addr = inet_addr(constants_setting_->multicast_group_ip_.c_str());
	group.imr_interface.s_addr = inet_addr(constants_setting_->lidar_ip_.c_str());
	if (setsockopt(sd_, IPPROTO_IP, IP_ADD_MEMBERSHIP,
				(char *)&group, sizeof(group)) < 0) {
		perror("adding multicast group");
		close(sd_);
		return -1;
	}
    return 0;
}

int CARNAVI::LidarSetting::get_lidar_setting(){
    return this->sd_;
}

