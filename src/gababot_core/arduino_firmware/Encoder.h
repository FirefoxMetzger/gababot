/*
 * Author: Sebastian Wallkoetter
 * Email: sebastian@wallkoetter.net
 * License: MIT
 */

#ifndef SOFT561_arduino_Encoder
#define SOFT561_arduino_Encoder

namespace SOFT561
{
namespace Arduino
{
class Encoder
{
    /*
     * Encoder is a class to wrap around the encoders found on the
     * initio Buggy. It offers a small layer of abstraction.
     * It is used by the Driver class to control wheel velocity.
     */

  private:
    /*
     * @_ports the hardware pins associated with the encoder
     */
    const struct Ports
    {
      Ports(const int signal);
      const int signal;
    } *_ports;

  public:
    Encoder(const int signal_port);
    ~Encoder();

    // read out the encoder
    // returns 1 if high (slot)
    // returns 0 if low (not slot)
    int getSignal();
};
}
}
#endif
