//	Author: Sebastian Wallkoetter
//	Email: sebastian@wallkoetter.net

#ifndef SOFT561_arduino_Motor
#define SOFT561_arduino_Motor

namespace SOFT561
{
namespace Arduino
{
enum Direction
{
  backward,
  forward,
  suspend
};

class Motor
{
  private:
    const struct Ports
    {
      Ports(int direction, int speed, int suspend, int current);
      const int direction;
      const int speed;
      const int suspend;
      const int current;
    }* _ports;
    float _speed;
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

    float getCurrentReading();

    void setDirection
    (
      Direction dir
    );
    Direction getDirection();
    void setSpeed(int speed);
};
}
}
#endif
