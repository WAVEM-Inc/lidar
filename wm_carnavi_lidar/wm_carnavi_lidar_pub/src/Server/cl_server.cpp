#include "Server/cl_server.hpp"
#include "Server/df_server.hpp"
#include <iostream>
cl_server::cl_server(){

}
int cl_server::fn_run(){
    std::cout<<"[Server] Start"<<std::endl;
    if(fn_server_setting()==-1){
        return -1;
    }
    if(fn_multicast_setting()==-1){
        return -1;
    }


}

int cl_server::fn_server_setting(){
    sd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sd < 0) {
		perror("opening datagram socket");
		return -1;
	}
    memset((char *) &localSock, 0, sizeof(localSock));
	localSock.sin_family = AF_INET;
	localSock.sin_port = htons(SERVER_PORT);
	localSock.sin_addr.s_addr  = INADDR_ANY;
    if (bind(sd, (struct sockaddr*)&localSock, sizeof(localSock))) {
		perror("binding datagram socket");
		close(sd);
		return -1;
	}
    return 0;
}
int cl_server::fn_multicast_setting(){
    group.imr_multiaddr.s_addr = inet_addr(MULTICAST_GROUP_IP);
	group.imr_interface.s_addr = inet_addr(LIDAR_IP);
	if (setsockopt(sd, IPPROTO_IP, IP_ADD_MEMBERSHIP,
				(char *)&group, sizeof(group)) < 0) {
		perror("adding multicast group");
		close(sd);
		return -1;
	}
    return 0;
}

int cl_server::fn_get_sd(){
    return this->sd;
}

