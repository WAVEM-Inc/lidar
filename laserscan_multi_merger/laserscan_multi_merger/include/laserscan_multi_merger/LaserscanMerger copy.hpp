#ifndef LASERSCAN_MULTI_MERGER_HPP_
#define LASERSCAN_MULTI_MERGER_HPP_

#include <iostream>
#include <Eigen/Dense>
#include "pcl_ros/transforms.hpp"
#include "pcl/point_cloud.h"
#include "pcl/point_types.h"
#include "pcl/io/pcd_io.h"
#include "pcl_conversions/pcl_conversions.h"
#include "tf2/exceptions.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "laser_geometry/laser_geometry.hpp"

#include "sensor_msgs/msg/point_cloud2.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "pcl_ros/transforms.hpp"

#include <string.h>
#include <vector>

using namespace std;
using namespace pcl;

using std::placeholders::_1;

class LaserscanMerger: public rclcpp::Node{
    public :
        LaserscanMerger();
    private :
        void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr scan, std::string topic);
	    void pointcloud_to_laserscan(Eigen::MatrixXf points, pcl::PCLPointCloud2 *merged_cloud);
};


#endif