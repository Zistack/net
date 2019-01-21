char
T::peek ()
{
	if (this->pointer < this->vector.size ())
	{
		return (char) this->vector[this->pointer];
	}
	else
	{
		throw Failure::EndOfResource::T ();
	}
}
