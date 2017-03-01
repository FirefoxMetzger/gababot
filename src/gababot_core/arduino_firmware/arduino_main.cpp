#include <ros.h>
#include <ArduinoHardware.h>
#include <geometry_msgs/Twist.h>
#include "Arduino.h"

#include "initio.h"
#include "Motor.h"
#include "Encoder.h"
#include "MotorControl.h"
#include "MovingBase.h"

using namespace SOFT561::Arduino;

Motor* motor_A;
Motor* motor_B;
Encoder* encoder_A;
Encoder* encoder_B;
MotorControl* driver_A;
MotorControl* driver_B;
MovingBase* base;

void lambdaCallback(const geometry_msgs::Twist& move_cmd)
{
 base->cmdVelCallback(move_cmd);
}

ros::NodeHandle nh;
ros::Subscriber<geometry_msgs::Twist> sub("/turtle1/cmd_vel", &lambdaCallback);

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
  
	pinMode(LED, OUTPUT);
}

void loop()
{
    //update all devices
    nh.spinOnce();
    driver_A->update();
    driver_B->update();
}
