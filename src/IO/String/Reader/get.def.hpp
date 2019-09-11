char
T::get ()
{
	if (this -> m_pointer < this -> m_string . size ())
	{
		char c = this -> m_string [this -> m_pointer];
		++ this -> m_pointer;
		return c;
	}
	else
	{
		throw Failure::EndOfResource::T ();
	}
}
