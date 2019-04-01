char
T::peek ()
{
	if (this -> begin == this -> end)
	{
		this -> refill ();
	}

	return this -> buffer [this -> begin];
}
