template <typename NonblockingInputStream>
char
T <NonblockingInputStream>::peek ()
{
	if (this -> begin == this -> end)
	{
		this -> refill ();
	}

	return this -> buffer [this -> begin];
}
