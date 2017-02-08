//	Author: Sebastian Wallkoetter
//	Email: sebastian@wallkoetter.net

#ifndef SOFT561_arduino_Motor
#define SOFT561_arduino_Motor

namespace SOFT561
{
	namespace arduino
	{
		class Motor
		{
			private:
				struct ports
				{
					const int direction;
					const int speed;
					const int brake;
					const int current;
				} ports;
				float speed;
				bool forward;
				bool suspend;
			
			public:
				Motor
				(
					const int direction_port, 
					const int speed_port, 
					const int suspend_port, 
					const int current_port
				);
				
				float getCurrentReading();
				
				void setDirection
				(
					Direction direction
				);
				Direction getDirection();
				void setSpeed();
		};
		
		typedef enum
		{
			backward = 0,
			forward,
			suspend
		} Direction;
	}
}
#endif