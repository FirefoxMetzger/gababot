#include "Arduino.h"
#include "Encoder.h"

namespace SOFT561
{
namespace Arduino
{
  Encoder::Ports::Ports(const int signal):signal(signal){}
  
  Encoder::Encoder(const int signal_port):_ports(new Encoder::Ports(signal_port)){}

  Encoder::~Encoder()
  {
    delete _ports;
  }

  int Encoder::getSignal()
  {
    return digitalRead(this->_ports->signal);
  }
}
}
