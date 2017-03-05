class KeyboardState
{
	constructor()
	{
		this.seq = Math.round(Date.now());
		this.last_pressed_idx = -1;
		this.keydown_length = 0;
		this.keydown = [];	
	}

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
