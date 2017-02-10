
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

        void update();
        void setSpeed(int speed);

        int getSpeed();
        
    };
  }
}
#endif
