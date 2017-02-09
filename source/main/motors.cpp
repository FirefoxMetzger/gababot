
#include <arduino.h>

#include "motor.h"

namespace SOFT561
{
	namespace arduino
	{
    Motor::Ports::Ports(int a, int b, int c, int d):
    direction(a),
    speed(b),
    suspend(c),
    current(d)
    {};
  
	  Motor::Motor
		(	
			const int direction_port, 
			const int speed_port, 
			const int suspend_port, 
			const int current_port
		):
   _speed(0)
		{		
			pinMode(this->_ports->direction, OUTPUT);
			pinMode(this->_ports->speed, OUTPUT);
			pinMode(this->_ports->suspend, OUTPUT);
			pinMode(this->_ports->current, INPUT);
		}
		
		float Motor::getCurrentReading()
		{
			//TODO: add current reading from this motor
			return 0.0;
		}
		
		void Motor::setDirection
		(
			Direction direction
		)
		{
			switch(direction)
			{
				case forward : 
					this->_suspend = false;
					this->_forward = true;
					
					digitalWrite(this->_ports->direction, HIGH);
					digitalWrite(this->_ports->suspend, LOW);
			
				case backward :
					this->_suspend = false;
					this->_forward = false;
					
					digitalWrite(this->_ports->direction, HIGH);
					digitalWrite(this->_ports->suspend, LOW);
				
				case suspend :
					this->_suspend = true;
					
					digitalWrite(this->_ports->suspend, HIGH);
			}
		}
		
		Direction Motor::getDirection()
		{
			if (this->_suspend)
			{
				return suspend;
			}
			else if (this->_forward)
			{
				return forward;
			}
			else 
			{
				return backward;
			}
		}
	}
}
