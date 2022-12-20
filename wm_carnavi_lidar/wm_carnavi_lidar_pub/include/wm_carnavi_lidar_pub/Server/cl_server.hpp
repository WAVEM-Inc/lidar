#ifndef SERVER
#define SERVER

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

class cl_server {
    public : 
        cl_server();
        int fn_run();
        int fn_get_sd();
    private :
        struct sockaddr_in localSock;
	    struct ip_mreq group;
	    int sd;

        int fn_server_setting();
        int fn_multicast_setting();

};

#endif 