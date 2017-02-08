#include "initio.h"

void setup()
{
  //configure the motor pins
  pinMode(MOTOR_A_DIRECTION,OUTPUT);
  pinMode(MOTOR_A_PWM,OUTPUT);
  pinMode(MOTOR_A_BREAK,OUTPUT);
  pinMode(MOTOR_A_CURRENT_SENSING,INPUT);

  pinMode(MOTOR_B_DIRECTION,OUTPUT);
  pinMode(MOTOR_B_PWM,OUTPUT);
  pinMode(MOTOR_B_BREAK,OUTPUT);
  pinMode(MOTOR_B_CURRENT_SENSING,INPUT);

  digitalWrite(MOTOR_A_DIRECTION,HIGH);
  digitalWrite(MOTOR_A_BREAK,LOW);
  analogWrite(MOTOR_A_PWM,100);
}

void loop()
{
  delay(1000);
  digitalWrite(MOTOR_A_DIRECTION,LOW);
  delay(1000);
  digitalWrite(MOTOR_A_DIRECTION,HIGH);
}
