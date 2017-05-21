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

function update_keyboard_image(keyboard_state)
{
    // check if WASD are currently pressed and not those keys
    wasd = [false, false, false, false];
    wasd_codes = ["KeyW", "KeyA", "KeyS", "KeyD"];
    
    // treat WASD as a number with base 2. i.e: D = 2^0, W=2^3, ...
    sum = 0;
    for (idx = 0; idx < 4; ++idx)
    {
        key = {code:wasd_codes[idx]};
        test_result = keyboard_state.inList(key);
        if (test_result.exists) 
        {
            wasd[idx] = true;
            sum += Math.pow(2,3-idx);
        }
    }
   
    // get the corresponding image
    base_path = "images/";
    images = [ 
    "WASD_clear.png",
    "D.png",
    "S.png",
    "SD.png",
    "A.png",
    "AD.png",
    "AS.png",
    "ASD.png",
    "W.png",
    "WD.png",
    "WS.png",
    "WSD.png",
    "WA.png", "WAD.png", "WAS.png", "WASD.png"];
    image_string = base_path.concat(images[sum]);
    document.getElementById("button_img").setAttribute("src",image_string);
}

// register callback on key down (add that key to the list of currently pressed
// keys
// @e -- the event data
onkeydown = function(e) 
{
	e = e || event; // fencing against IE
	keyboard_state.addKey(e);
	//document.getElementById("currently_pressed_string").innerHTML = JSON.stringify(keyboard_state);
	update_keyboard_image(keyboard_state);

	var keyboard_message = new ROSLIB.Message(keyboard_state);
	keyboard_topic.publish(keyboard_message);
}

// register callback on key up (remove key from currently pressed keys)
// @e -- the event data
onkeyup = function(e)
{
	e = e || event;
	keyboard_state.removeKey(e);
	//document.getElementById("currently_pressed_string").innerHTML = JSON.stringify(keyboard_state);
	update_keyboard_image(keyboard_state);
	
	var keyboard_message = new ROSLIB.Message(keyboard_state);
	keyboard_topic.publish(keyboard_message);
}
