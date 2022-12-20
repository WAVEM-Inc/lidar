#ifndef SERVER_RECV
#define SERVER_RECV
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include "Server/df_server_recv.hpp"
#include "ros/ros.h"
#include <vector>
#include <iostream>
#include<signal.h>
#include<unistd.h>

class cl_server_recv{
    public : 
        cl_server_recv();
        int fn_run();
        void fn_set_sd(int sd);
    private : 
        int sd;
        void* memmem(const void *buf, size_t buflen,const void *pattern, size_t len);
        float fn_degree_to_radian(float degree);
        

};
#endif