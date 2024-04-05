#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "LaserscanMerger.hpp"

int main(int argc,char** argv){
    sleep(3);
    rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<LaserscanMerger>());
	rclcpp::shutdown();
    return 0;
}