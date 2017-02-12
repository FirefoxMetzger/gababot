#include "Arduino.h"
#include "Encoder.h"
#include "Motor.h"

#include "MotorControl.h"

namespace SOFT561
{
namespace Arduino
{
MotorControl::MotorControl
(
  const int motor_direction,
  const int motor_speed,
  const int motor_suspend,
  const int motor_current,
  const int encoder_signal
):
  _shared_objects(false),
  _motor(new Motor(motor_direction, motor_speed, motor_suspend, motor_current)),
  _encoder(new Encoder(encoder_signal)),
  _target_speed(0),
  _current_speed(0)
{}

MotorControl::MotorControl
(
  Motor* motor,
  Encoder* encoder
):
  _shared_objects(true),
  _motor(motor),
  _encoder(encoder),
  _target_speed(0),
  _current_speed(motor->getSpeed())
{}

MotorControl::~MotorControl()
{
  this->_motor->setSpeed(0);  
  if(!this->_shared_objects)
  {
    delete this->_motor;
    delete this->_encoder;
  }
}

void MotorControl::update()
{
  int signal = this->_encoder->getSignal();
  this->_motor->setSpeed(this->_target_speed);
  //TODO: adjust motor speed based on sensor readings
}

void MotorControl::setSpeed(int speed)
{
  this->_target_speed = abs(speed);
  
  if (speed > 0)
  {
    this->_motor->setDirection(forward);
  }
  else if (speed == 0)
  {
    this->_motor->setDirection(suspend);
  }
  else
  {
    this->_motor->setDirection(backward);
  }
}

}
}

