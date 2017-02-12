
#include "Arduino.h"

#include "SerialCommunication.h"

namespace SOFT561
{
namespace Arduino
{
SerialCommunication::SerialCommunication(int baud):
  _in_message(none),
  _out_message(none)
{
  Serial.begin(baud);
  while (!Serial) {}
}

void SerialCommunication::push(SerialMessage msg)
{
  this->_out_message = msg;
}

SerialMessage SerialCommunication::pop()
{
  SerialMessage return_message = this->_in_message;
  this->_in_message = none;
  return return_message;
}

void SerialCommunication::update()
{
  int msg = Serial.read();
  msg -= 48;
  this->_in_message = static_cast<SerialMessage>(msg);
  
  Serial.print(this->_out_message);
  Serial.print("\r\n");
  this->_out_message = none;
}
}
}

