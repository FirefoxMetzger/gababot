#include "arduino.h"
#include "initio.h"
#include "motor.h"
#include "MotorControl.h"

void setup()
{
  pinMode(LED, OUTPUT);
}

void whatever()
{

}

void loop()
{
  SOFT561::Arduino::Motor* motor_A = new SOFT561::Arduino::Motor(MOTOR_A_DIRECTION, MOTOR_A_PWM, MOTOR_A_BREAK, MOTOR_A_CURRENT_SENSING);
  SOFT561::Arduino::Motor* motor_B = new SOFT561::Arduino::Motor(MOTOR_B_DIRECTION, MOTOR_B_PWM, MOTOR_B_BREAK, MOTOR_B_CURRENT_SENSING);

  motor_A->setDirection(SOFT561::Arduino::forward);
  motor_B->setDirection(SOFT561::Arduino::backward);

  int speed_counter = 0;
  int speed_inc = 1;

  while (true)
  {
    motor_A->setSpeed(speed_counter);
    motor_B->setSpeed(speed_counter);

    if (speed_counter > 255 || speed_counter < 0)
    {
      speed_inc *= -1;
    }
    speed_counter += speed_inc;
    delay(100);
  }
}
