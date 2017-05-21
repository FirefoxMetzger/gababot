/*
 * Author: Sebastian Wallkoetter
 * Email: sebastian@wallkoetter.net
 * License: MIT
 */

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
    /*
     * A class to convert a keyboard message into a twist message
     * it stores the last detected keyboard message and constructs the according
     * twist message upon request.
     * When constructing this class arbitrary keys can be mapped to arbitrary
     * twist messages. When multiple keys are pressed, the twist message will be
     * the sum of all messages being mapped to.
     */
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
		    /*
		     * A class storing a direction in which the robot can be steered.
		     * If the coresponding key is pressed, this direction is added to
		     * the resulting Twist message.
		     * If multiple keys are pressed the value is added multiple times.
		     */
			private:
				double* _value;
				std::vector<std::string> key_binds;

			public:
			
			    // get the direction value stored for this direction
				double* getValue();
				
				// check if the pressed key is in the list of keys that trigger
				// this direction
				// @key -- the pressed key
				bool keyPressed(jake::Key key);
				
				// add the direction vector to the twist message being passed in
				// @msg -- the Twist message
				void addValueToMessage(geometry_msgs::Twist &msg);

                // add a key to the list of keys triggering it
                // @key -- the key to add
				void addKey(std::string key);
				
				// compare the given array to the to the stored direction vector
				// @in_array -- the array to compare
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

        // The callack message triggered whenever a new keyboard message is
        // captured
        // @msg -- the Keyboard message object
		void keyboardCallback(const jake::Keyboard msg);
		
		// publish a twist message that is the sum of all twist vectors that are
		// activated by the last published Keyboard message
		void publishTwist();
};

}
}
#endif
