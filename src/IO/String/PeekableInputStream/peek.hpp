char
T::peek ()
{
	if (this->pointer < this->string.size ())
	{
		return this->string[this->pointer];
	}

	throw EOF::T ();
}