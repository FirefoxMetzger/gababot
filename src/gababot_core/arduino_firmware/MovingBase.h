#include <ros.h>
#include <geometry_msgs/Twist.h>
//#include <nav_msgs/Odometry.h>

#include "MotorControl.h"

#ifndef SOFT561_ARDUINO_MOVINGBASE
#define SOFT561_ARDUINO_MOVINGBASE
namespace SOFT561
{
namespace Arduino
{
class MovingBase 
{
	private:
		MotorControl* _MotorA;
		MotorControl* _MotorB;

	public:
		MovingBase
		(
			MotorControl* Motor_A, 
			MotorControl* Motor_B
		);
		~MovingBase();

		void cmdVelCallback(const geometry_msgs::Twist& move_cmd);
};	
}
}
#endif
