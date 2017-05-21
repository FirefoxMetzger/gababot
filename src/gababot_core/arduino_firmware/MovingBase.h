/*
 * Author: Sebastian Wallkoetter
 * Email: sebastian@wallkoetter.net
 * License: MIT
 */

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
    /*
     * A class handling the base of the Initio. It has two motor controllers
     * and provides a callback that will compute and set the desired motor speed
     * values whenever a new ROS message comes in.
     */
	private:
		MotorControl* _MotorA;
		MotorControl* _MotorB;
		int _watchdog_counter;
        int _watchdog_timeout;

	public:
		MovingBase
		(
			MotorControl* Motor_A, 
			MotorControl* Motor_B
		);
		~MovingBase();

        // The callback to be executed whenever a new ROS message is received
		void cmdVelCallback(const geometry_msgs::Twist& move_cmd);
		
		// update the watchdog that will stop the motors in case of signal loss
		void updateWatchdog();
        
        // set the number of cycles after which the watchdog stops the motors
        // @timeout -- the number of cycles
        void setTimeout(int timeout);
};	
}
}
#endif
