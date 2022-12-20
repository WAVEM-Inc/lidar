
#include"Server/cl_server.hpp"
#include"Server/cl_server_recv.hpp"

int main(int argc,char** argv){
    ros::init(argc,argv,"wavem_carnavi_lidar_pub");
    cl_server server;
    cl_server_recv server_recv;
    server.fn_run();
    server_recv.fn_set_sd(server.fn_get_sd());
    server_recv.fn_run();
    return 0;
}