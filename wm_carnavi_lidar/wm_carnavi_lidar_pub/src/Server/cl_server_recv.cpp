#include"Server/cl_server_recv.hpp"

#include"sensor_msgs/LaserScan.h"
#include<math.h>
cl_server_recv::cl_server_recv(){
    sd=0;
}

int cl_server_recv::fn_run(){
    unsigned char lidar_head[LIDAR_HEADE_SIZE] = {LIDAR_HEADER,LIDAR_PRODUCT_LINE,LIDAR_ID,LIDAR_COMMAND_MODE};
    unsigned char databuf[DATA_BUF_SIZE];
    float range_data[MAX_RANGE_SIZE];
    int datalen;
    int lp;
    int ch;
    char *pars_point;
    int read_len;
	float dist_dot=0;

    float angle_increment_degree = 0.25;
    float angle_max_degeree = 60;
    float angle_min_degeree = -60;
    ros::NodeHandle nh;
    ros::Publisher lidar_pub_ch_zero = nh.advertise<sensor_msgs::LaserScan>(TOPIC_CH0,SCAN_PUB_QUEUE_SIZE,NULL,NULL,NULL,true);
    ros::Publisher lidar_pub_ch_one = nh.advertise<sensor_msgs::LaserScan>(TOPIC_CH1,SCAN_PUB_QUEUE_SIZE,NULL,NULL,NULL,true);

    if(sd==0){
        std::cout<<"Plz sd setting"<<std::endl;
        return -1;
    }
    datalen = sizeof(databuf);
    sensor_msgs::LaserScan scan;
    scan.header.frame_id = FRAME;
    scan.angle_increment = fn_degree_to_radian(angle_increment_degree);
    scan.angle_max = fn_degree_to_radian(angle_max_degeree);
    scan.angle_min = fn_degree_to_radian(angle_min_degeree);
    scan.range_max = 70;
    scan.range_min = 0.25;
    scan.scan_time = 1/SCAN_HZ;
    int scan_lp=0;
    while(ros::ok()){
        scan.header.seq = scan_lp++;
        scan.header.stamp = ros::Time::now();
		memset(databuf,0,sizeof(databuf));
		memset(range_data,0,sizeof(range_data));
		read_len=read(sd, databuf, datalen);
		printf("\n");
		if (read_len < 0) {
			perror("reading datagram message");
			close(sd);
			exit(1);
		}
		
		for(lp=0;lp<MAX_RANGE_SIZE;lp++){
		    printf("%02X,",databuf[lp]);
		}
        
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
                scan.ranges=temp;
				lidar_pub_ch_zero.publish(scan);
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
                scan.ranges=temp;
                lidar_pub_ch_one.publish(scan);
			}
			printf("ch%d:",ch);
            
			for(lp=0;lp<480;lp++)
			{
				printf("%f,",lp+1,range_data[lp]);
			}
			printf("\n");
            ros::spinOnce();
		}
		signal(SIGTSTP, SIG_IGN);
	}
    
    return 0;
}

void cl_server_recv::fn_set_sd(int sd){
    this->sd=sd;
}

void* cl_server_recv::memmem(const void *buf, size_t buflen,const void *pattern, size_t len){
    	char *bf = (char *)buf, *pt = (char *)pattern, *p = bf ;

	while (len <= (buflen - (p - bf)))
	{
		if (NULL != (p= (char*)memchr(p, (int)(*pt), buflen - (p - bf))))
		{
			if (!memcmp(p, pattern, len))
				return p;
			else  ++p;
		}
		else  break;
	}
	return NULL;
}

float cl_server_recv::fn_degree_to_radian(float degree){
	std::cout<<"@@@"<<degree*M_PI/(float)180<<std::endl;
    return degree*M_PI/(float)180;
}
