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
	private:
		ros::NodeHandle _ns;
		ros::Publisher _pub;
		ros::Subscriber _sub;
		geometry_msgs::Twist _current_velocity;
		 
		struct {
			struct Vector3
			{
				std::vector<std::string> x;
				std::vector<std::string> y;
				std::vector<std::string> z;
			};
			Vector3 linear_positive;
			Vector3 linear_negative;
			Vector3 angular_positive;
			Vector3 angular_negative;
		} _key_binding;

		bool _hasBindingMatch(std::vector<std::string> bindings, const jake::Key key);		

	public:
		TwistKeyboardCallback(ros::NodeHandle ns);
		~TwistKeyboardCallback();

		void keyboardCallback(const jake::Keyboard msg);
		void publishTwist();
};

}
}
#endif
