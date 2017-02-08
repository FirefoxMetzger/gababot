
#include <arduino.h>

#include "motor.h"

namespace SOFT561
{
	namespace arduino
	{
		Motor::Motor
		(	
			const int direction_port, 
			const int speed_port, 
			const int suspend_port, 
			const int current_port
		)
		{
			this.ports.direction = direction_port;
			this.ports.speed = speed_port;
			this.ports.suspend = suspend_port;
			this.ports.current = current_port;
			
			this.speed = 0;
			this.suspend = true;
			this.forward = true;
			
			pinMode(this.pins.direction, OUTPUT);
			pinMode(this.pins.speed, OUTPUT);
			pinMode(this.pins.suspend, OUTPUT);
			pinMode(this.pins.current, INPUT);
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
					this.suspend = false;
					this.forward = true;
					
					digitalWrite(this.pins.direction, HIGH);
					digitalWrite(this.pins.suspend, LOW);
			
				case backward :
					this.suspend = false;
					this.forward = false;
					
					digitalWrite(this.pins.direction, HIGH);
					digitalWrite(this.pins.suspend, LOW);
				
				case suspend :
					this.suspend = true;
					
					digitalWrite(this.pins.suspend, HIGH);
			}
		}
	}
}