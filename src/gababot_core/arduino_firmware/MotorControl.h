/*
 * Author: Sebastian Wallkoetter
 * Email: sebastian@wallkoetter.net
 * License: MIT
 */

#ifndef SOFT651_Arduino_MotorControl
#define SOFT651_Arduino_MotorControl

#include "Motor.h"
#include "Encoder.h"

namespace SOFT561
{
namespace Arduino
{
class MotorControl
{
  /*
   * A controller for a motor. It sets speed (using the Motor class) and reads
   * out the encoder to ensure that the desired speed is kept.
   */
   
  private:
	const bool _shared_objects;
	Motor* _motor;
	Encoder* _encoder;
	int _target_speed;
	int _current_speed;
	
  public:
	MotorControl
	(
	  const int motor_direction, 
	  const int motor_speed, 
	  const int motor_suspend, 
	  const int motor_current, 
	  const int encoder_signal
	);
	MotorControl(Motor* motor, Encoder* encoder);
	~MotorControl();

    // update loop for the controller. compute the next raw speed values given
    // the encoder measurement and the desired speed
	void update();
	
	// set the desired speed
	// @speed -- the desired speed
	void setSpeed(int speed);

    // get the current speed
	int getSpeed();
};
}
}
#endif
