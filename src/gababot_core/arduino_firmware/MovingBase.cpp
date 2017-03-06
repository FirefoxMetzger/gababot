#include <ros.h>
#include <geometry_msgs/Twist.h>
//#include <nav_msgs/Odometry.h>

#include "MotorControl.h"

#include "MovingBase.h"

namespace SOFT561
{
namespace Arduino
{
MovingBase::MovingBase::MovingBase
(
	MotorControl* Motor_A,
	MotorControl* Motor_B
):
_MotorA(Motor_A),
_MotorB(Motor_B)
{}
MovingBase::~MovingBase(){}

void MovingBase::cmdVelCallback(const geometry_msgs::Twist& move_cmd)
{
	const float l = 0.2;	
	const float omega = move_cmd.angular.z;
	const float x = move_cmd.linear.x;

	const float v_r = x + (omega * l)/2;
	const float v_l = x - (omega * l)/2;
	int speed_left = static_cast<int>(v_l);
	int speed_right = static_cast<int>(v_r);

	this->_MotorA->setSpeed(-speed_left);
	this->_MotorB->setSpeed(speed_right);
}
}
}
