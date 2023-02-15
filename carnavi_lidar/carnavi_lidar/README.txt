1. 빌드 및 설정하기

 0) 압축 파일을 풉니다.

  # unzip carnavi_lidar.zip -d ~/

 1) 압축 파일에 첨부된 carnavi_lidar 소스로부터 드라이버를 빌드합니다.

  # source /opt/ros/melodic/setup.bash
  # mkdir -p ~/ros_catkin_ws/src/
  # cp ~/carnavi_lidar ~/ros_catkin_ws/src/ -Rf
  # cd ~/ros_catkin_ws
  # catkin_make
  # source ~/ros_catkin_ws/devel/setup.bash

 2) ros 관련 환경 설정하기
  : ~/.bashrc를 열어서 가장 아래에 다음 두줄을 추가합니다.
   # vi ~/.bashrc
   source /opt/ros/melodic/setup.bash
   source ~/ros_catkin_ws/devel/setup.bash
  : 최초 한번만 설정하시면 됩니다.

 3) 고정 ip 설정하기
  : ip -> 192.168.123.100
  : netmask -> 255.255.255.0
  : gateway -> 192.168.123.1

2. 실행하기
 1) 새로운 터미널에서 roscore를 실행합니다.
  # roscore
 2) 새로운 터미널에서 rosrun carnavi_lidar carnavi_lidar_node
  # rosrun carnavi_lidar carnavi_lidar_node
 3) 새로운 터미널에서 rviz를 실행합니다.
  # rviz -d ~/carnavi_lidar_frame.rviz
