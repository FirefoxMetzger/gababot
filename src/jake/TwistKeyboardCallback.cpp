#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

#include <vector>

#include "TwistKeyboardCallback.h"
#include "jake/Keyboard.h"
#include "jake/Key.h"

using namespace SOFT561::JAKE;

TwistKeyboardCallback::TwistKeyboardCallback(ros::NodeHandle ns) 
{
	this->_ns = ns;
	this->_pub = this->_ns.advertise<geometry_msgs::Twist>("cmd_vel",1000);	
	this->_sub = ns.subscribe("keyboard",1000, &TwistKeyboardCallback::keyboardCallback, this);

	this->_key_binding.linear_positive.x.push_back("W");
	this->_key_binding.linear_positive.x.push_back("w");
	this->_key_binding.linear_negative.x.push_back("s");
	this->_key_binding.angular_positive.z.push_back("d");
	this->_key_binding.angular_negative.z.push_back("a");

    this->_current_velocity.linear.x = 0;
	this->_current_velocity.linear.y = 0;
	this->_current_velocity.linear.z = 0;
	this->_current_velocity.angular.x = 0;
	this->_current_velocity.angular.y = 0;
	this->_current_velocity.angular.z = 0;    
}

TwistKeyboardCallback::~TwistKeyboardCallback()
{

}

bool TwistKeyboardCallback::_hasBindingMatch
(
	std::vector<std::string> bindings, 
	const jake::Key key
)
{
	for(auto symbol : bindings)
	{
		if
		(
			key.key.compare(symbol) == 0 ||
			key.code.compare(symbol) == 0
		)
		{
			return true;
		}
	}
	return false;
}

void TwistKeyboardCallback::keyboardCallback(const jake::Keyboard msg) 
{
	for(int idx = 0; idx < msg.keydown_length; ++idx)
	{
		jake::Key current_key = msg.keydown[idx];
		if (this->_hasBindingMatch(this->_key_binding.linear_positive.x, current_key))
		{
			this->_current_velocity.linear.x += 1;
		}
		else if (this->_hasBindingMatch(this->_key_binding.linear_negative.x, current_key))
		{
			this->_current_velocity.linear.x -= 1;
		}
		else if (this->_hasBindingMatch(this->_key_binding.angular_positive.z, current_key))
		{
			this->_current_velocity.angular.z += 1;
		}
		else if (this->_hasBindingMatch(this->_key_binding.angular_negative.z, current_key))
		{
			this->_current_velocity.angular.z -= 1;
		}

	}
}

void TwistKeyboardCallback::publishTwist()
{
	this->_pub.publish(this->_current_velocity);
}
