
#include "motor.h"
#include "encoder.h"

#ifndef SOFT651_Arduino_MotorControl
#define SOFT651_Arduino_MotorControl
namespace SOFT561
{
  namespace Arduino
  {
    class MotorControl
    {
      private:
        bool shared_objects;
        Motor _motor;
        Encoder _encoder;
        int _target_speed;
        int _current_speed;
        
      public:
        MotorControl();
        MotorControl(Motor motor, Encoder encoder);
        ~MotorControl();

        void update();
        void setSpeed(int speed);
        void setDirection(Direction direction);

        int getSpeed();
        
    };
  }
}
#endif
