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
      struct Ports
        {
          Ports(int a, int b, int c, int d);
           int direction;
           int speed;
           int suspend;
           int current;
        };
    
			private:
				Ports* _ports;
				float _speed;
				bool _forward;
				bool _suspend;
			
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
