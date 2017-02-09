//	Author: Sebastian Wallkoetter
//	Email: sebastian@wallkoetter.net

#ifndef SOFT561_arduino_Encoder
#define SOFT561_arduino_Encoder

namespace SOFT561
{
	namespace Arduino
	{
		class Encoder
		{
			private:
				const struct Ports
				{
          Ports();
					const int signal;
				} _ports;
			
			public:
				Encoder(int signal_port);
       ~Encoder();
				
				bool getSignal();
		};
	}
}
#endif
