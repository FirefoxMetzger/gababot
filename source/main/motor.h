//	Author: Sebastian Wallkoetter
//	Email: sebastian@wallkoetter.net

#ifndef SOFT561_arduino_Motor
#define SOFT561_arduino_Motor

namespace SOFT561
{
	namespace arduino
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
				struct ports
				{
					 int direction;
					 int speed;
					 int brake;
					 int current;
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
					Direction dir
				);
				Direction getDirection();
				void setSpeed();
		};
	}
}
#endif
