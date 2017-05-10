// Author: Sebastian Wallkötter
// Email: sebastian@wallkoetter.net
// License: MIT

// A class representing the ROS Key message.
class Key 
{
    // Simple constructor to store a key. Only extracting from the JS event what
    // we need and dropping everything else.
    // @code -- the code of the key i.e. 'KeyW' independant of keyboard layout
    // @key -- the (layout dependant) character of the key 
    //         (i.e. 'KeyQ' = A on frensh keyboards)
	constructor(key)
	{
		this.code = key.code;
		this.key = key.key;
		this.location = key.location;
	}
}
