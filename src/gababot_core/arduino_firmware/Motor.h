/*
 * Author: Sebastian Wallkoetter
 * Email: sebastian@wallkoetter.net
 * License: MIT
 */
 
#ifndef SOFT561_arduino_Motor
#define SOFT561_arduino_Motor

namespace SOFT561
{
namespace Arduino
{
// An enum specifying the direction in which the wheels turn
enum Direction
{
  backward,
  forward,
  suspend
};

class Motor
{
  /*
   * A Class wrapping a hardware motor and providing a layer of abstraction.
   * After creation it allows to simply set the speed and the class will do the
   * necessary hardware settings. 
   */
  private:
    const struct Ports
    {
      /*
       * a struct storing the hardware pins needed to control the motor
       */
      Ports
      (
        const int direction, 
        const int speed, 
        const int suspend, 
        const int current
      );
      
      const int direction;
      const int speed;
      const int suspend;
      const int current;
    }* _ports;
    int _speed;
    bool _forward;
    bool _suspend;

  public:
    Motor
    (
      const int direction_port,
      const int speed_port,
      const int suspend_port,
      const int current_port
    );
    ~Motor();

    // return the current value applied to the motor
    float getCurrentReading();

    // set the direction in which the motor should turn
    // if set to suspend, the break is set and speed is 0
    // @dir -- the direction to set
    void setDirection(Direction dir);
    
    // get the direction in which the motor is currently spinning
    Direction getDirection();
    
    // set the speed of the motor
    // @speed -- the speed to set
    void setSpeed(int speed);

    // get the speed of the motor
    int getSpeed();
};
}
}
#endif
