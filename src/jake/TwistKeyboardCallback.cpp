#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

#include <vector>
#include <string>
#include <iostream>

#include "TwistKeyboardCallback.h"
#include "jake/Keyboard.h"
#include "jake/Key.h"

using namespace SOFT561::JAKE;

TwistKeyboardCallback::TwistKeyboardCallback(ros::NodeHandle ns) 
{
	this->_ns = ns;
	this->_pub = this->_ns.advertise<geometry_msgs::Twist>("cmd_vel",1000);	
	this->_sub = ns.subscribe
	(
		"keyboard",1000, 
		&TwistKeyboardCallback::keyboardCallback, 
		this
	);
	double direction[] = {250,0,0,0,0,0};
	double direction2[] = {-250,0,0,0,0,0};
	double direction3[] = {0,0,0,0,0,2500};
	double direction4[] = {0,0,0,0,0,-2500};
	TwistKeyboardCallback::Direction* foo = new TwistKeyboardCallback::Direction(direction);
	foo->addKey("w");
	this->_directions.push_back(foo);

	foo = new TwistKeyboardCallback::Direction(direction2);
	foo->addKey("s");
	this->_directions.push_back(foo);
	
	foo = new TwistKeyboardCallback::Direction(direction4);
	foo->addKey("a");
	this->_directions.push_back(foo);
	
	foo = new TwistKeyboardCallback::Direction(direction3);
	foo->addKey("d");
	this->_directions.push_back(foo);
}

TwistKeyboardCallback::~TwistKeyboardCallback()
{

}


void TwistKeyboardCallback::keyboardCallback(const jake::Keyboard msg) 
{
	this->_last_message = msg;
}

void TwistKeyboardCallback::publishTwist()
{
	this->_pub.publish(this->_getTwistMsg());
}

// private functions

geometry_msgs::Twist TwistKeyboardCallback::_getTwistMsg()
{
	geometry_msgs::Twist msg;

	msg.linear.x = 0;
	msg.linear.y = 0;
	msg.linear.z = 0;
	msg.angular.x = 0;
	msg.angular.y = 0;
	msg.angular.z = 0;

	for (auto key : this->_last_message.keydown)
	{
		for ( auto dir : this->_directions)
		{
			if ( dir->keyPressed(key) ) 
			{
				dir->addValueToMessage(msg);
			}
		}
	}

	return msg;
}

void TwistKeyboardCallback::_addKeyToDirection(double* dir,
		std::string key)
{
	for( auto direction : this->_directions )
	{
		if ( direction->compareArray(dir))
		{
			direction->addKey(key);
		}
	}
	TwistKeyboardCallback::Direction *new_direction = 
		new TwistKeyboardCallback::Direction(dir);
	new_direction->addKey(key);
	this->_directions.push_back(new_direction);
}

// implementation of subclass

void TwistKeyboardCallback::Direction::addValueToMessage( geometry_msgs::Twist &msg)
{
	msg.linear.x += this->_value[0];
	msg.linear.y += this->_value[1];
	msg.linear.z += this->_value[2];
	msg.angular.x += this->_value[3];
	msg.angular.y += this->_value[4];
	msg.angular.z += this->_value[5];
}

TwistKeyboardCallback::Direction::Direction
(
	double* value
):
	_value(new double[6])
{
	for(auto idx = 0; idx < 6; ++idx) {
		this->_value[idx] = value[idx];
}
}

double* TwistKeyboardCallback::Direction::getValue()
{
	return this->_value;
}

bool TwistKeyboardCallback::Direction::keyPressed(jake::Key key)
{
	for(auto symbol : this->key_binds)
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

void TwistKeyboardCallback::Direction::addKey(std::string key)
{
	this->key_binds.push_back(key);	
}

bool TwistKeyboardCallback::Direction::compareArray(double* in_array)
{
	for(auto idx = 1; idx < 6; ++idx)
	{
		if(this->_value[idx] != in_array[idx])
		{
			return false;
		}
	}
	return true;
}
