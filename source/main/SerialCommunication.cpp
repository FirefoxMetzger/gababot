
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
  //read message
  if(Serial.available() >= 1)
  {
    SerialMessage msg = this->convertMessage(Serial.read());
    if(msg != none)
    {
      this->_in_message = msg;
    }
  }
  else
  {
    this->_in_message = none;
  }

  //write message
  if(this->_out_message != none)
  {
    
    Serial.print(this->_out_message);
    Serial.print("\r\n");
    this->_out_message = none;
  }
}

SerialMessage SerialCommunication::convertMessage(int msg) const
{
  if(msg < static_cast<int>(none))
  {
    return none;
  }
  
  if(msg > static_cast<int>(up)) 
  {
    return none;
  }
  
  SerialMessage return_value = static_cast<SerialMessage>(msg);
  switch(static_cast<SerialMessage>(msg))
  {
    case none:
    case up:
    case down:
    case left:
    case right:
      break;
    default:
      return none;
  }
  
  return return_value;
}

}
}

