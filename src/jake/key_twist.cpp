#include "ros/ros.h"
#include "TwistKeyboardCallback.h"

int main(int argc, char **argv)
{
ros::init(argc, argv, "key_twist");
ros::NodeHandle ns("~");
SOFT561::JAKE::TwistKeyboardCallback *converter = 
	new SOFT561::JAKE::TwistKeyboardCallback(ns);
ros::Rate loop_rate(10);

while (ros::ok())
{
	converter->publishTwist();	
	ros::spinOnce();
	loop_rate.sleep();
}

return 0;
}
