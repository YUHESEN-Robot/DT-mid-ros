#ifndef __CANCONTROL_NODE_H__
#define __CANCONTROL_NODE_H__



#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "geometry_msgs/Twist.h"
#include "tf/transform_broadcaster.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/Imu.h"
#include "geometry_msgs/Twist.h"
#include "yhs_can_msgs/ctrl_DGT_cmd.h"
#include "yhs_can_msgs/io_cmd.h"
#include "yhs_can_msgs/ctrl_DGT_fb.h"
#include "yhs_can_msgs/lr_wheel_fb.h"
#include "yhs_can_msgs/rr_wheel_fb.h"
#include "yhs_can_msgs/lf_wheel_fb.h"
#include "yhs_can_msgs/rf_wheel_fb.h"
#include "yhs_can_msgs/io_fb.h"
#include "yhs_can_msgs/front_free_ctrl_cmd.h"
#include "yhs_can_msgs/rear_free_ctrl_cmd.h"
#include "yhs_can_msgs/bms_Infor.h"
#include "yhs_can_msgs/bms_flag_Infor.h"
#include "yhs_can_msgs/odo_fb.h"
#include "yhs_can_msgs/Veh_Diag_fb.h"

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#include <string>

#include <linux/can.h>
#include <linux/can/raw.h>


namespace yhs_tool {
class CanControl
{
public:
	CanControl();
	~CanControl();
	
	void run();
private:
	ros::NodeHandle nh_;

	ros::Publisher ctrl_DGT_fb_pub_;
	ros::Publisher lr_wheel_fb_pub_;
	ros::Publisher rr_wheel_fb_pub_;
	ros::Publisher io_fb_pub_;
	ros::Publisher rf_wheel_fb_pub_;
	ros::Publisher lf_wheel_fb_pub_;
	ros::Publisher bms_Infor_pub_;
	ros::Publisher bms_flag_Infor_pub_;

	ros::Publisher odo_fb_pub_;
	ros::Publisher Veh_Diag_fb_pub_;

	ros::Subscriber ctrl_DGT_cmd_sub_;
	ros::Subscriber io_cmd_sub_;
	ros::Subscriber front_free_ctrl_cmd_sub_;
	ros::Subscriber rear_free_ctrl_cmd_sub_;

	boost::mutex cmd_mutex_;

	int dev_handler_;
	can_frame send_frames_[2];
	can_frame recv_frames_[1];


	void io_cmdCallBack(const yhs_can_msgs::io_cmd msg);
	void ctrl_cmdCallBack(const yhs_can_msgs::ctrl_DGT_cmd msg);
	void front_free_ctrl_cmdCallBack(const yhs_can_msgs::front_free_ctrl_cmd msg);
	void rear_free_ctrl_cmdCallBack(const yhs_can_msgs::rear_free_ctrl_cmd msg);


	void recvData();

};

}


#endif

