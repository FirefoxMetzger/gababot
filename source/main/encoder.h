//	Author: Sebastian Wallkoetter
//	Email: sebastian@wallkoetter.net

#ifndef SOFT561_arduino_Encoder
#define SOFT561_arduino_Encoder

namespace SOFT561
{
	namespace arduino
	{
		class Encoder
		{
			private:
				struct ports
				{
					int signal;
				} ports;
			
			public:
				Encoder(int signal_port);
				
				bool getSignal();
		};
	}
}
#endif