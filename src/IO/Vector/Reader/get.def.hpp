char
T::get ()
{
	if (this -> pointer < this -> vector . size ())
	{
		uint8_t c = this -> vector [this -> pointer];
		++ this -> pointer;
		return (char) c;
	}
	else
	{
		throw Failure::EndOfResource::T ();
	}
}
