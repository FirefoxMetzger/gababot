#include "arduino.h"
#include "initio.h"
#include "motor.h"
#include "MotorControl.h"
#include "SerialCommunication.h"

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  SOFT561::Arduino::Motor* motor_A = new SOFT561::Arduino::Motor(MOTOR_A_DIRECTION, MOTOR_A_PWM, MOTOR_A_BREAK, MOTOR_A_CURRENT_SENSING);
  SOFT561::Arduino::Motor* motor_B = new SOFT561::Arduino::Motor(MOTOR_B_DIRECTION, MOTOR_B_PWM, MOTOR_B_BREAK, MOTOR_B_CURRENT_SENSING);

  SOFT561::Arduino::SerialCommunication com = SOFT561::Arduino::SerialCommunication(9600);

  while (true)
  {
    SOFT561::Arduino::SerialMessage foo = com.pop();
    com.push(foo);
    com.update();
    
    delay(1000);
  }
}
