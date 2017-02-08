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
					int direction;
					int speed;
					int brake;
					int current;
				} ports;
				float speed;
				bool forward;
				bool suspend;
			
			public:
				Motor(int direction_port, int speed_port, int suspend_port, int current_port);
				
				float getCurrentReading();
				
				void setDirection(Direction direction);
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