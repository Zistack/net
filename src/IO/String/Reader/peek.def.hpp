char
T::peek ()
{
	if (this -> m_pointer < this -> m_string . size ())
	{
		return this -> m_string [this -> m_pointer];
	}
	else
	{
		throw Failure::EndOfResource::T ();
	}
}
