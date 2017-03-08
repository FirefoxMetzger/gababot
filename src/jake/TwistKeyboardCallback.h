#include "ros/ros.h"
#include "jake/Keyboard.h"
#include "jake/Key.h"
#include "geometry_msgs/Twist.h"
#include <string>
#include <vector>

#ifndef SOFT561_JAKE_TWISTKEYBOARDCALLBACK
#define SOFT561_JAKE_TWISTKEYBOARDCALLBACK
namespace SOFT561 {
namespace JAKE{

class TwistKeyboardCallback {
	enum TWIST_DIRECTION
	{
		LINEAR_X=0,
		LINEAR_Y=1,
		LINEAR_Z=2,
		ANGULAR_X=3,
		ANGULAR_Y=4,
		ANGULAR_Z=5
	};
	private:
		class Direction {
			private:
				double* _value;
				std::vector<std::string> key_binds;

			public:
				double* getValue();
				bool keyPressed(jake::Key key);
				void addValueToMessage(geometry_msgs::Twist msg);

				void addKey(std::string key);
				bool compareArray(double* in_array);

				Direction(double* value);
				~Direction();
		};


	private:
		ros::NodeHandle _ns;
		ros::Publisher _pub;
		ros::Subscriber _sub;
		
		std::vector<Direction*> _directions;
		jake::Keyboard _last_message;

		geometry_msgs::Twist _getTwistMsg();
		void _addKeyToDirection(double* dir,
				std::string key);

	public:
		TwistKeyboardCallback(ros::NodeHandle ns);
		~TwistKeyboardCallback();

		void keyboardCallback(const jake::Keyboard msg);
		void publishTwist();
};

}
}
#endif
