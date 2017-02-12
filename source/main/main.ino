#include "arduino.h"
#include "initio.h"
#include "motor.h"
#include "encoder.h"
#include "MotorControl.h"
#include "SerialCommunication.h"

using namespace SOFT561::Arduino;

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  //initialize all classes here. in setup they are out of scope and global is bad
  Motor* motor_A = new Motor(MOTOR_A_DIRECTION, MOTOR_A_PWM, MOTOR_A_BREAK, MOTOR_A_CURRENT_SENSING);
  Motor* motor_B = new Motor(MOTOR_B_DIRECTION, MOTOR_B_PWM, MOTOR_B_BREAK, MOTOR_B_CURRENT_SENSING);
  Encoder* encoder_A = new Encoder(ENCODER_A);
  Encoder* encoder_B = new Encoder(ENCODER_B);

  MotorControl* driver_A = new MotorControl(motor_A, encoder_A);
  MotorControl* driver_B = new MotorControl(motor_B, encoder_B);

  SerialCommunication* com = new SerialCommunication(9600);

  while (true)
  {
    SerialMessage foo = com->pop();
    com->push(foo);

    switch(foo)
    {
      up:
        driver_A->setSpeed(200);
        driver_B->setSpeed(200);
        break;
      down:
        driver_A->setSpeed(-200);
        driver_B->setSpeed(-200);
        break;
      left:
        driver_A->setSpeed(200);
        driver_B->setSpeed(-200);
        break;
      right:
        driver_A->setSpeed(-200);
        driver_B->setSpeed(200);
        break;
      none:
        driver_A->setSpeed(0);
        driver_B->setSpeed(0);
        break;
    }


    //update all devices
    com->update();
    driver_A->update();
    driver_B->update();

    //random delay
    delay(500);
  }
}
