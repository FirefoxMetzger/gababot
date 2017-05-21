/*
 * Author: Sebastian Wallkoetter
 * Email: sebastian@wallkoetter.net
 * License: MIT
 */

#include <Arduino.h>

#include "Motor.h"

namespace SOFT561
{
namespace Arduino
{
// initializer list for Ports struct
Motor::Ports::Ports(int a, int b, int c, int d):
  direction(a),
  speed(b),
  suspend(c),
  current(d)
{};

// constructor for the motor
Motor::Motor
(
  const int direction_port,
  const int speed_port,
  const int suspend_port,
  const int current_port
):
  _ports(new Motor::Ports(direction_port,speed_port,suspend_port,current_port)),
  _speed(0),
  _forward(true),
  _suspend(true)
{
  pinMode(this->_ports->direction, OUTPUT);
  pinMode(this->_ports->speed, OUTPUT);
  pinMode(this->_ports->suspend, OUTPUT);
  pinMode(this->_ports->current, INPUT);
}

// destructor for the motor
Motor::~Motor()
{
  delete _ports;
}

float Motor::getCurrentReading()
{
  // return the current currently applied to the motor
  return digitalRead(this->_ports->current);
}

void Motor::setDirection
(
  Direction direction
)
{
  switch (direction)
  {
    case forward :
      this->_suspend = false;
      this->_forward = true;

      // set break and direction
      digitalWrite(this->_ports->direction, HIGH);
      digitalWrite(this->_ports->suspend, LOW);
      break;

    case backward :
      this->_suspend = false;
      this->_forward = false;

      // set break and direction
      digitalWrite(this->_ports->direction, LOW);
      digitalWrite(this->_ports->suspend, LOW);
      break;

    case suspend :
      this->_suspend = true;

      // set break
      digitalWrite(this->_ports->suspend, HIGH);
  }
}

Direction Motor::getDirection()
{
  if (this->_suspend)
  {
    return suspend;
  }
  else if (this->_forward)
  {
    return forward;
  }
  else
  {
    return backward;
  }
}

void Motor::setSpeed(int speed)
{
  if (speed >= 0 && speed <= 255)
  {
    // speed is within bounds and can actually be set
    analogWrite(this->_ports->speed, speed);
    this->_speed = speed;
  }
  else if (speed > 255)
  {
    // speed above maximum set as high as we can
    analogWrite(this->_ports->speed, 255);
    this->_speed = 255;
  }
  else
  {
    // speed below 0 set to 0
    analogWrite(this->_ports->speed, 0);
    this->_speed = 0; 
  }
}

int Motor::getSpeed()
{
  return this->_speed;
}

}
}
