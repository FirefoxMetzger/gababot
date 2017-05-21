/*
 * Author: Sebastian Wallkoetter
 * Email: sebastian@wallkoetter.net
 * License: MIT
 */

#include "ros/ros.h"
#include "TwistKeyboardCallback.h"

// the main entry point for jake twist
int main(int argc, char **argv)
{
ros::init(argc, argv, "key_twist");
ros::NodeHandle ns("~");

// get an instance of the converter
SOFT561::JAKE::TwistKeyboardCallback *converter = 
	new SOFT561::JAKE::TwistKeyboardCallback(ns);
ros::Rate loop_rate(25);

while (ros::ok())
{
    // publish a twist message based on the last received keyboard message
	converter->publishTwist();	
	
	ros::spinOnce();
	loop_rate.sleep();
}

return 0;
}
