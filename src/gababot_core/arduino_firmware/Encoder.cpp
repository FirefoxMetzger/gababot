/*
 * Author: Sebastian Wallkoetter
 * Email: sebastian@wallkoetter.net
 * License: MIT
 */

#include "Arduino.h"
#include "Encoder.h"

namespace SOFT561
{
namespace Arduino
{
  // constructor for Ports
  Encoder::Ports::Ports(const int signal):signal(signal){}
  
  // constructor for Encoder
  Encoder::Encoder(const int signal_port):_ports(new Encoder::Ports(signal_port)){}

  // destructor
  Encoder::~Encoder()
  {
    delete _ports;
  }

  int Encoder::getSignal()
  {
    // return the signal
    return digitalRead(this->_ports->signal);
  }
}
}
