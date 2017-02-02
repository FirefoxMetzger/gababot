
namespace SOFT561
{
	namespace arduino
	{
		struct Motor
		{
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
		};
	}
}
