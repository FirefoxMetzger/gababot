/*
 * Author: Sebastian Wallkoetter
 * Email: sebastian@wallkoetter.net
 * License: MIT
 */

#include <ros.h>
#include <geometry_msgs/Twist.h>
//#include <nav_msgs/Odometry.h>

#include "MotorControl.h"

#include "MovingBase.h"

namespace SOFT561
{
namespace Arduino
{

// constructor for moving base
MovingBase::MovingBase::MovingBase
(
	MotorControl* Motor_A,
	MotorControl* Motor_B
):
_MotorA(Motor_A),
_MotorB(Motor_B),
_watchdog_counter(0),
_watchdog_timeout(1000)
{}

// destructor -- nothing to do
MovingBase::~MovingBase(){}

void MovingBase::cmdVelCallback(const geometry_msgs::Twist& move_cmd)
{
    // extract variables used and set constants
    const float l = 0.2;
    float omega = move_cmd.angular.z;
    float x = move_cmd.linear.x;

    // the buggy is actually moving backwards, so flip
    // direction of speed
    x = -1 * x;

    // calculate the velocity of each motor using the model of a tank drive
    // Note: This values calculated here are in m/s. The buggy needs a value 
    //       within [0, 255] which determines the ratio of the PWM. Determining
    //       this conversion is very hardware dependant and was omitted in this
    //       project. Instead just set those values directly
	const float v_r = x + (omega * l)/2;
	const float v_l = x - (omega * l)/2;
    int speed_left = static_cast<int>(v_l);
    int speed_right = static_cast<int>(v_r);

    // set the speed of each motor
    this->_MotorA->setSpeed(speed_left);
    this->_MotorB->setSpeed(speed_right);

    // (re-)set the watchdog so it can timeout the motors if needed
    this->_watchdog_counter = this->_watchdog_timeout;
}

void MovingBase::updateWatchdog()
{
    // decrease watchdog counter
    this->_watchdog_counter -= 1;

    // if necessarry stop motors
    if (this->_watchdog_counter <= 0)
    {
        this->_watchdog_counter = 0;

        this->_MotorA->setSpeed(0);
        this->_MotorB->setSpeed(0);
    }
}

void MovingBase::setTimeout(int timeout)
{
    // update the number of cycles until timeout
    this->_watchdog_timeout = timeout;
}
}
}
