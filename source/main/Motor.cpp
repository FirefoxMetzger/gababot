
#include <arduino.h>

#include "motor.h"

namespace SOFT561
{
namespace Arduino
{
Motor::Ports::Ports(int a, int b, int c, int d):
  direction(a),
  speed(b),
  suspend(c),
  current(d)
{};

Motor::Motor
(
  const int direction_port,
  const int speed_port,
  const int suspend_port,
  const int current_port
):
  _ports(new Motor::Ports(direction_port,speed_port,suspend_port,current_port)),
  _speed(0),
  _forward(false),
  _suspend(true)
{
  pinMode(this->_ports->direction, OUTPUT);
  pinMode(this->_ports->speed, OUTPUT);
  pinMode(this->_ports->suspend, OUTPUT);
  pinMode(this->_ports->current, INPUT);

  this->setDirection(forward);
  pinMode(speed_port,100);

  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
}

Motor::~Motor()
{
  delete _ports;
}

float Motor::getCurrentReading()
{
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

      digitalWrite(this->_ports->direction, HIGH);
      digitalWrite(this->_ports->suspend, LOW);
      digitalWrite(13,LOW);

      break;

    case backward :
      this->_suspend = false;
      this->_forward = false;

      digitalWrite(this->_ports->direction, HIGH);
      digitalWrite(this->_ports->suspend, LOW);
      break;

    case suspend :
      this->_suspend = true;

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
  analogWrite(this->_ports->speed, speed);
  this->_speed = speed;
}

int Motor::getSpeed()
{
  return this->_speed;
}

}
}
