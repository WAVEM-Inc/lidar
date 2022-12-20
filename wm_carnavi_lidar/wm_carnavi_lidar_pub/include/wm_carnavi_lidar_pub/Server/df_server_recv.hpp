#define DATA_BUF_SIZE 2048
#define MAX_RANGE_SIZE 1024
#define LIDAR_HEADE_SIZE 4

#define LIDAR_HEADER 0xFA
#define LIDAR_PRODUCT_LINE 0x03
#define LIDAR_ID 0xD0
#define LIDAR_COMMAND_MODE 0xDD

#define CH0 0xC0
#define CH1 0xC1

#define SCAN_PUB_QUEUE_SIZE 15
#define SCAN_HZ 15
#define TOPIC_CH0 "/scan/ch00"
#define TOPIC_CH1 "/scan/ch01"

#define FRAME "base_laser_link"