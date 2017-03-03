class KeyboardState
{
	constructor()
	{
		this.seq = Date.now();
		this.last_pressed_idx = -1;
		this.keydown_length = 0;
		this.keydown = [];	
	}

	keydown(key)
	{
		var key_tester = this.inList(key);
		this.seq = Date.now();

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

	keyup(key)
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

	inList(key)
	{
		for (var i = 0; i < this.keydown_length; ++i)
		{
			if(assertKey(key,this.keydown[i]))
			{
				return {
					exists:true,
					idx:i,
				};
			}	
		}	
		return {exists:false};
	}

	assertKeys(key1,key2) {
		// technically I have to check both ways
		// however I know that I pass in the class attribute as
		// a second value, this I can save one loop
		for(property in key2.getOwnPropertyNames())
		{
			if( key1.hasOwnProperty(property) )
			{
				if(key1.property !== key2.property) 
				{
					return false;
				}
			}
		}
		return true;
	}
}
