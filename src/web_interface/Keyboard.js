// Author: Sebastian Wallkötter
// Email: sebastian@wallkoetter.net
// License: MIT

// assume JQuery is loaded by index.html (it is indeed)
// include Key (a single key in all currently pressed keys)
$.getScript("Key.js", function(data, textStatus, jqxhr) {
    console.log( data ); // Data returned
    console.log( textStatus ); // Success
    console.log( jqxhr.status ); // 200
    console.log( "Load was performed." );
})

// A class to represent ROS Keyboard messages
// roslibjs converts JSON messages into ROS messages. This fact can be exploited
// by implementing a JS class of the same structure as the ROS keyboard message.
// This class can have nice methods making it easy to add / remove keys and
// can then be serialized into JSON and turned into a ROS message
class KeyboardState
{
    //mimic ros message structure
    // @seq -- a timestamp
    // @keydown_length -- how many keys are pressed
    // @keydown -- a array of Key() objects, one for each currently pressed key
	constructor()
	{
		this.seq = Math.round(Date.now());
		this.last_pressed_idx = -1;
		this.keydown_length = 0;
		this.keydown = [];	
	}

    // add a key to the list of currently pressed keys
    // @key -- the key to add
	addKey(key)
	{
		this.seq = Math.round(Date.now());

		var key_tester = this.inList(key);
		if (key_tester.exists)
		{
			this.last_pressed_idx = key_tester.idx;
		}
		else
		{
			this.last_pressed_idx = this.keydown_length;
			this.keydown_length += 1;
			this.keydown.push(new Key(key))
		}
	}

    // remove a key from the list of currently pressed keys
    // if the key is not in the list, do nothing
    // @key -- the key to remove
	removeKey(key)
	{
		var key_tester = this.inList(key);
		if (key_tester.exists)
		{
			this.keydown.splice(key_tester.idx,1);
			this.keydown_length -= 1;
		}
		else
		{
			console.debug("Tried to remove nonexistant key.")
		}
	}

    // check if a key is in the list of currently pressed keys
    // @key -- the key to check existance of
	inList(key)
	{
		for (var i = 0; i < this.keydown_length; ++i)
		{
			if(this.assertKey(key,this.keydown[i]))
			{
				return {
					exists:true,
					idx:i,
				};
			}	
		}	
		return {exists:false};
	}

    // check if @key1 and @key2 are the same
    // @key1 -- a key to compare
    // @key2 -- another key to compare
    
    // Technically this could be an method of Key() to compare something against
    // itself. Maybe move this around later (TODO low priority).
	assertKey(key1,key2)
   	{
		// technically I have to check both ways
		// however I know that I pass in the class attribute as
		// a second value, this I can save one loop
		if (key1.code === key2.code)
		{
			return true;
		}
		else
		{
			return false;
		}
		//below assert is not working --- why? --- low priority
		for(var property in key2)
		{
			if (!key2.hasOwnProperty(property))
			{
				continue;
			}
			else if ( !key1.hasOwnProperty(property) )
			{
				return false;
			}
			else if (key1[property] !== key2[property])
			{
				document.write('not matching: '+property);
				return false;
			}
		}
		document.write("matching")
		return true;
	}
}
