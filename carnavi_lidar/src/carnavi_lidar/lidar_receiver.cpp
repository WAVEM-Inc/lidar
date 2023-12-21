#include "lidar_receiver.hpp"
#include <cstring>
#include <cmath>
#include <unistd.h>
#include<signal.h>
#include <utility> 
CARNAVI::LidarReceiver::LidarReceiver():Node("carnavi_lidar_node"){
}
CARNAVI::LidarReceiver::LidarReceiver(std::unique_ptr<Constants::Receiver> constants_receiver):Node("carnavi_lidar_node"),constants_receiver_(std::move(constants_receiver)){
}

void CARNAVI::LidarReceiver::receiver_setting(int sd){
    this->sd_ = sd;
}

int CARNAVI::LidarReceiver::receiver_run(){
    unsigned char lidar_head[LIDAR_HEADE_SIZE] = {LIDAR_HEADER,LIDAR_PRODUCT_LINE,LIDAR_ID,LIDAR_COMMAND_MODE};
    unsigned char databuf[DATA_BUF_SIZE];
    float range_data[MAX_RANGE_SIZE];
    int datalen;
    int lp;
    int ch;
    char *pars_point;
    int read_len;
	float dist_dot=0;

    if(sd_==0){
        std::cout<<"Plz sd setting"<<std::endl;
        return -1;
    }
    rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr lidar_pub_ch00 = this->create_publisher<sensor_msgs::msg::LaserScan>(constants_receiver_->topic_ch0_,constants_receiver_->scan_pub_queue_size_);
    rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr lidar_pub_ch01 = this->create_publisher<sensor_msgs::msg::LaserScan>(constants_receiver_->topic_ch1_,constants_receiver_->scan_pub_queue_size_);
    sensor_msgs::msg::LaserScan temp_scan = lidar_setting();
    temp_scan.header.stamp = this->now();

    datalen = sizeof(databuf);
    while(rclcpp::ok()){

            memset(databuf,0,sizeof(databuf));
            memset(range_data,0,sizeof(range_data));
            read_len=read(sd_, databuf, datalen);
            printf("\n");

            if (read_len < 0) {
                perror("reading datagram message");
                close(sd_);
                exit(1);
            }
            
            for(lp=0;lp<MAX_RANGE_SIZE;lp++){
                printf("%02X,",databuf[lp]);
            }
            std::cout<<"!"<<__LINE__<<std::endl;
            if((pars_point=(char*)memmem(databuf, sizeof(databuf),lidar_head,sizeof(lidar_head)))!=NULL)
            {
                memcpy(databuf,pars_point,read_len);
                for(lp=0;lp<480;lp++)	
                {
                    dist_dot=databuf[lp*2+7] + (float)databuf[lp*2+8]/100;
                    range_data[lp]=dist_dot;
                }
                if(databuf[LIDAR_HEADE_SIZE] == CH0)	//ch0
                {
                    ch=0;
                    for(lp=0;lp<480;lp++)	
                    {
                        dist_dot=databuf[lp*2+7] + (float)databuf[lp*2+8]/100;
                        range_data[lp]=dist_dot;
                    }
                    int range_data_size=(sizeof(range_data)/sizeof(range_data[0]))-544;
                    std::vector<float> temp(range_data,range_data+range_data_size);
                    temp_scan.ranges = temp;
                    lidar_pub_ch00->publish(temp_scan);
                }
                else if(databuf[LIDAR_HEADE_SIZE] == CH1)	//ch1
                {
                    ch=1;
                    for(lp=0;lp<480;lp++)	
                    {
                        dist_dot=databuf[lp*2+7] + (float)databuf[lp*2+8]/100;
                        range_data[lp]=dist_dot;
                    }
                    int range_data_size=(sizeof(range_data)/sizeof(range_data[0]))-544;
                    std::vector<float> temp(range_data,range_data+range_data_size);
                    temp_scan.ranges = temp;
                    lidar_pub_ch01->publish(temp_scan);
                }
                printf("ch%d:",ch);
                
                for(lp=0;lp<480;lp++)
                {
                    printf("%f,",lp+1,range_data[lp]);
                }
                printf("\n");
            }
            signal(SIGTSTP, SIG_IGN);
        }
    
    return 0;

}

void* CARNAVI::LidarReceiver::memmem(const void *buf, size_t buflen,const void *pattern, size_t len){
    char *bf = (char *)buf, *pt = (char *)pattern, *p = bf ;
	while (len <= (buflen - (p - bf))){
		if (NULL != (p= (char*)memchr(p, (int)(*pt), buflen - (p - bf)))){
			if (!memcmp(p, pattern, len))
				return p;
			else  ++p;
		}
		else  break;
	}
	return NULL;
}

float CARNAVI::LidarReceiver::degree_to_radian(float degree){
	//std::cout<<"@@@"<<degree*M_PI/(float)180<<std::endl;
    return degree*M_PI/(float)180;
}

sensor_msgs::msg::LaserScan CARNAVI::LidarReceiver::lidar_setting(){
    sensor_msgs::msg::LaserScan init_scan;
    init_scan.header.frame_id = constants_receiver_->topic_frame_;
    init_scan.angle_increment = degree_to_radian(constants_receiver_->scan_increment_);
    init_scan.angle_max =  degree_to_radian(constants_receiver_->scan_angle_max_);
    init_scan.angle_min = degree_to_radian(constants_receiver_->scan_angle_min_);
    init_scan.range_max = constants_receiver_->scan_range_max_;
    init_scan.range_min =constants_receiver_->scan_range_min_;
    init_scan.scan_time = 1/constants_receiver_->scan_hz_;
    return init_scan;
}



CARNAVI::LidarReceiver::~LidarReceiver(){
    close(sd_);
}
