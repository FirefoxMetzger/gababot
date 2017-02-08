
#include <arduino.h>

#include "motor.h"

namespace SOFT561
{
	namespace arduino
	{
		Motor::Motor:forward{0}
	//  speed{0},
	//  forward{true},
	//  suspend{true},
		(	
			const int direction_port, 
			const int speed_port, 
			const int suspend_port, 
			const int current_port
		)
		{			
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
		
		Direction Motor::getDirection()
		{
			if (this.suspend)
			{
				return suspend;
			}
			else if (this.forward)
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
