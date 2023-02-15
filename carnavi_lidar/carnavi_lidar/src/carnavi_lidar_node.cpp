#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

#define LIDAR_MODEL_R300    0
#define LIDAR_MODEL_R2      1

#define LIDAR_MODEL         LIDAR_MODEL_R2

#if (LIDAR_MODEL == LIDAR_MODEL_R2)
#define UDP_PORT            5000
#define UDP_IP_ADDR         "192.168.123.200"
#define MULTICAST_IP_ADDR   "224.0.0.5"
#define PACKET_BUF_SIZE     1024

#define PROTO_HEAD          0xFA
#define DISTANCE_DATA_MODE  0xDD
#define CONFIG_SETTING_MODE 0xCF
#define ENGINEER_MODE       0xDB
#define NAK_MODE            0xF0
#define FIRMWARE_BOOT_LOAD  0xFB

#define V_ANGLE_RES         3.f
#define H_ANGLE_RES         0.25f
#define V_ANGLE_FOV         2.f
#define H_ANGLE_FOV         120.f
#define V_ANGLE_START       0.f
#define V_ANGLE_FINISH      2.f
#define H_ANGLE_START       0.f
#define H_ANGLE_FINISH      120.f

#define H_POINT_COUNT       (120 * 4)
#define V_CHANNEL_COUNT     2

#define ROS_FRAME_HZ        15

#elif (LIDAR_MODEL == LIDAR_MODEL_R300)

#define UDP_PORT            5000
#define UDP_IP_ADDR         "192.168.123.200"
#define MULTICAST_IP_ADDR   "224.0.0.5"
#define PACKET_BUF_SIZE     4096

#define PROTO_HEAD          0xFA
#define DISTANCE_DATA_MODE  0xDD
#define CONFIG_SETTING_MODE 0xCF
#define ENGINEER_MODE       0xDB
#define NAK_MODE            0xF0
#define FIRMWARE_BOOT_LOAD  0xFB

#define V_ANGLE_RES         3.f
#define H_ANGLE_RES         0.25f
#define V_ANGLE_FOV         1.f
#define H_ANGLE_FOV         300.f
#define V_ANGLE_START       0.f
#define V_ANGLE_FINISH      1.f
#define H_ANGLE_START       0.f
#define H_ANGLE_FINISH      300.f

#define H_POINT_COUNT       (300 * 4)
#define V_CHANNEL_COUNT     1

#define ROS_FRAME_HZ        10

#endif

typedef struct _carnavi_lidar_proto_t
{
    uint8_t head;
    uint8_t product_line;
    uint8_t id;
    uint8_t command_mode;
    uint8_t command_parameter;
    uint16_t data_len;
    uint8_t data[PACKET_BUF_SIZE];
    uint8_t checksum;
} carnavi_lidar_proto_t;

typedef struct _point_t
{
    float x;
    float y;
    float z;
    float i;
} point_t;

int main(int argc, char** argv)
{
    int sock_fd, addr_len, recv_len;
    sockaddr_in server_addr, client_addr;
    uint8_t packet_buf[PACKET_BUF_SIZE];
    point_t point_buffer[V_CHANNEL_COUNT * H_POINT_COUNT];
    int point_count;
    int i, j, size, pos;
    int packet_len;
    const uint32_t point_size = 16;

    ros::init(argc, argv, "carnavi_lidar_pub");
    ros::NodeHandle nh;
    ros::Publisher carnavi_lidar_pub = nh.advertise<sensor_msgs::PointCloud2>("/carnavi_lidar_cloud", 1);
    ros::Rate loop_rate(ROS_FRAME_HZ);

    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0)
    {
        perror("Error");
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(UDP_PORT);

    if (bind(sock_fd, (sockaddr*)&server_addr, sizeof(server_addr)) != 0)
    {
        perror("Error");
    }

#if 1
    struct ip_mreq mreq;
    const char *group = MULTICAST_IP_ADDR;

    mreq.imr_multiaddr.s_addr = inet_addr(group);
    mreq.imr_interface.s_addr = inet_addr(UDP_IP_ADDR);

    if (setsockopt(sock_fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*) &mreq, sizeof(mreq)) < 0)
    {
        perror("Error");
    }
#endif

#if 1
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 5000;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0)
    {
        perror("Error");
    }
#endif

    memset(point_buffer, 0, sizeof(point_buffer));
    point_count = 0;

    while (ros::ok())
    {
        addr_len = sizeof(client_addr);
        memset(packet_buf, 0, sizeof(packet_buf));
        packet_len = 0;
        while (1)
        {
            recv_len = recvfrom(sock_fd, &packet_buf[packet_len], PACKET_BUF_SIZE, 0, 
                    (sockaddr*)&client_addr, (socklen_t*)&addr_len);
            if (recv_len > 0)
            {
                packet_len += recv_len;
#if (LIDAR_MODEL == LIDAR_MODEL_R300)
                continue;
#else
                break;
#endif
            }
            else
            {
                if (packet_len > 0)
                {
                    break;
                }
            }
            usleep(0);
        }

        packet_len = 0;
        size = pos = 0;
        carnavi_lidar_proto_t lidar_frame;

        size = sizeof(lidar_frame.head);
        memcpy(&lidar_frame.head, &packet_buf[pos], size);
        pos += size;

        if (lidar_frame.head != PROTO_HEAD)
        {
            ROS_INFO("Frame is not started with PROTO_HEAD\n");
            continue;
        }

        size = sizeof(lidar_frame.product_line);
        memcpy(&lidar_frame.product_line, &packet_buf[pos], size);
        pos += size;
        size = sizeof(lidar_frame.id);
        memcpy(&lidar_frame.id, &packet_buf[pos], size);
        pos += size;
        size = sizeof(lidar_frame.command_mode);
        memcpy(&lidar_frame.command_mode, &packet_buf[pos], size);
        pos += size;
        size = sizeof(lidar_frame.command_parameter);
        memcpy(&lidar_frame.command_parameter, &packet_buf[pos], size);
        pos += size;
        lidar_frame.data_len  = (packet_buf[pos++] << 8) & 0xff00;
        lidar_frame.data_len |= (packet_buf[pos++] & 0x00ff);
        size = lidar_frame.data_len;
        memcpy(&lidar_frame.data[0], &packet_buf[pos], size);
        pos += size;
        size = sizeof(lidar_frame.checksum);
        memcpy(&lidar_frame.checksum, &packet_buf[pos], size);
        pos += size;

        uint8_t checksum = 0x00;
        for (i = 0; i < 7; i++)
        {
            checksum ^= packet_buf[i];
        }

        if (lidar_frame.command_mode == DISTANCE_DATA_MODE)
        {
            int v_count, h_count, point_len;
            float v_angle, h_angle;
            float v_sin, v_cos, h_sin, h_cos;
            float x, y, z;

            if (checksum != lidar_frame.checksum)
            {
                ROS_INFO("CheckSum Error Wanted : 0x%02x, Calc : 0x%02x", lidar_frame.checksum, checksum);
                continue;
            }

            if ((lidar_frame.command_parameter & 0xC0) == 0xC0)
            {
                v_count = (lidar_frame.command_parameter & 0x0F);
                v_angle = V_ANGLE_START + (v_count * V_ANGLE_RES);
                v_sin = sin((v_angle) * M_PI / 180);
                v_cos = cos((v_angle) * M_PI / 180);
                if (v_count == 0)
                {
                    memset(point_buffer, 0, sizeof(point_buffer));
                    point_count = 0;
                }
            }

            point_len = lidar_frame.data_len - 1;
            for (i = 0, h_count = 0; i < point_len; i+=2, h_count++)
            {
                h_angle = H_ANGLE_START + (h_count * H_ANGLE_RES);
                h_sin = sin((h_angle) * M_PI / 180);
                h_cos = cos((h_angle) * M_PI / 180);
                float distance = (1.f * (float)lidar_frame.data[i] + (0.1f * (float)lidar_frame.data[i+1]));

                x = (distance) * v_cos * h_cos;
                y = (distance) * v_cos * h_sin;
                z = (distance) * v_sin;

                point_buffer[point_count].x = x;
                point_buffer[point_count].y = y;
                point_buffer[point_count].z = z;
                point_buffer[point_count].i = v_count;
                point_count++;
            }

            if (v_count >= (V_CHANNEL_COUNT-1))
            {
                sensor_msgs::PointCloud2 cloud;
                cloud.header.frame_id = std::string("carnavi_lidar_frame");
                cloud.header.stamp = ros::Time::now();
                cloud.fields.resize(4);
                cloud.fields[0].name = "x";
                cloud.fields[0].offset = 0;
                cloud.fields[0].datatype = sensor_msgs::PointField::FLOAT32;
                cloud.fields[0].count = 1;

                cloud.fields[1].name = "y";
                cloud.fields[1].offset = 4;
                cloud.fields[1].datatype = sensor_msgs::PointField::FLOAT32;
                cloud.fields[1].count = 1;

                cloud.fields[2].name = "z";
                cloud.fields[2].offset = 8;
                cloud.fields[2].datatype = sensor_msgs::PointField::FLOAT32;
                cloud.fields[2].count = 1;

                cloud.fields[3].name = "intensity";
                cloud.fields[3].offset = 12;
                cloud.fields[3].datatype = sensor_msgs::PointField::FLOAT32;
                cloud.fields[3].count = 1;

                cloud.data.resize(std::max(1, point_count) * point_size, 0x00);
                cloud.point_step = point_size;
                cloud.row_step = cloud.data.size();
                cloud.height = 1;
                cloud.width = cloud.row_step / point_size;
                cloud.is_bigendian = false;
                cloud.is_dense = true;

                uint8_t *ptr = cloud.data.data();
                for (i = 0; i < point_count; i++)
                {
                    *(reinterpret_cast<float*>(ptr +  0)) = point_buffer[i].x;
                    *(reinterpret_cast<float*>(ptr +  4)) = point_buffer[i].y;
                    *(reinterpret_cast<float*>(ptr +  8)) = point_buffer[i].z;
                    *(reinterpret_cast<float*>(ptr + 12)) = point_buffer[i].i;
                    ptr += point_size;
                }
                carnavi_lidar_pub.publish(cloud);
                memset(point_buffer, 0, sizeof(point_buffer));
                point_count = 0;
            }
        }
        else if (lidar_frame.command_mode == CONFIG_SETTING_MODE)
        {
        }
        else if (lidar_frame.command_mode == ENGINEER_MODE)
        {
        }
        else if (lidar_frame.command_mode == NAK_MODE)
        {
        }
        else if (lidar_frame.command_mode == FIRMWARE_BOOT_LOAD)
        {
        }
        else
        {
            ROS_INFO("[%s:%d] Unknown Command Mode\n", __func__, __LINE__);
        }
        ros::spinOnce();
        //loop_rate.sleep();
    }

    close(sock_fd);

    return 0;
}
