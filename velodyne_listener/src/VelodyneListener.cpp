#include"VelodyneListener.hpp"

VelodyneListener::VelodyneListener():Node("velodyne_listner_node"){
    sub_scan_ = this->create_subscription<LidarMSG>("/scan",
                                                    1,
                                                    std::bind(&VelodyneListener::scan_callback
                                                            ,this
                                                            ,std::placeholders::_1));
}

void VelodyneListener::scan_callback(const std::shared_ptr<LidarMSG> scan){
    std::cout<<scan->range_max <<std::endl;
}
