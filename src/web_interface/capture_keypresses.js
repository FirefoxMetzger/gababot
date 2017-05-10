// Author: Sebastian Wallkötter
// Email: sebastian@wallkoetter.net
// License: MIT

// This file defines callbacks for JS keypress events. They track all key press
// and key release events and keep a list of keys pressed.
// Whenever a new key is pressed, send a new ROS event
//      Note: Holding a key down will repeatedly fire new keydown events


// this file depends on:
// - Keyboard.js
// it is included in index.html (because browsers don't yet support import)

// using global variables -- my JS-fu is not to great. There is probably a nicer
// way of doing this that I don't yet know about.
if (typeof keyboard_state == 'undefined')
{
    keyboard_state = new KeyboardState();
}

// register callback on key down (add that key to the list of currently pressed
// keys
// @e -- the event data
onkeydown = function(e) 
{
	e = e || event; // fencing against IE
	keyboard_state.addKey(e);
	document.getElementById("currently_pressed_string").innerHTML = JSON.stringify(keyboard_state);

	//var keyboard_message = new ROSLIB.Message(keyboard_state);
	//keyboard_topic.publish(keyboard_message);
}

// register callback on key up (remove key from currently pressed keys)
// @e -- the event data
onkeyup = function(e)
{
	e = e || event;
	keyboard_state.removeKey(e);
	document.getElementById("currently_pressed_string").innerHTML = JSON.stringify(keyboard_state);
}
