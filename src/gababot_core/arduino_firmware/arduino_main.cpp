/*
 * Author: Sebastian Wallkoetter
 * Email: sebastian@wallkoetter.net
 * License: MIT
 */

#include <ros.h>
#include <ArduinoHardware.h>
#include <geometry_msgs/Twist.h>
#include "Arduino.h"

#include "initio.h"
#include "Motor.h"
#include "Encoder.h"
#include "MotorControl.h"
#include "MovingBase.h"

/*
 * This is the entry point of the firmware.
 * When the Arduino is powered this code runs. It follows the conventions
 * of the Arduino IDE, but is crosscompiled using AVR Dude and CMake.
 */

using namespace SOFT561::Arduino;

// declare variables globally (as to conform with standard)
// classes used my the firmware
Motor* motor_A;
Motor* motor_B;
Encoder* encoder_A;
Encoder* encoder_B;
MotorControl* driver_A;
MotorControl* driver_B;
MovingBase* base;

// a lambda function to subscribe to the movement topic
// this wraps a classes member function
// @move_cmd -- the message
void lambdaCallback(const geometry_msgs::Twist& move_cmd)
{
 base->cmdVelCallback(move_cmd);
}

//declare ROS variabes
ros::NodeHandle nh;
ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &lambdaCallback);

//initialize variables in an arduino conform way
void setup()
{
	motor_A = new Motor(
			MOTOR_A_DIRECTION, 
			MOTOR_A_PWM, 
			MOTOR_A_BREAK, 
			MOTOR_A_CURRENT_SENSING);
	motor_B = new Motor(
			MOTOR_B_DIRECTION, 
			MOTOR_B_PWM, 
			MOTOR_B_BREAK, 
			MOTOR_B_CURRENT_SENSING);
	encoder_A = new Encoder(ENCODER_A);
	encoder_B = new Encoder(ENCODER_B);
	driver_A = new MotorControl(motor_A, encoder_A);
	driver_B = new MotorControl(motor_B, encoder_B);
	base = new MovingBase(driver_A,driver_B);

        nh.initNode();
        nh.subscribe(sub);
}

// main loop as per arduino specification
// update the motor drivers and watchdog
// also check if the timeout value has changed and update accordingly
void loop()
{
    //update all devices
    nh.spinOnce();
    driver_A->update();
    driver_B->update();
    base->updateWatchdog();

    // syncronize watchdog with Parameter Server
    int timeout;
    nh.getParam("/watchdog_cycles",&timeout,1);
    base->setTimeout(timeout);
}
