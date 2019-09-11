char
T::get ()
{
	if (this -> m_pointer < this -> m_vector . size ())
	{
		uint8_t c = this -> m_vector [this -> m_pointer];
		++ this -> m_pointer;
		return (char) c;
	}
	else
	{
		throw Failure::EndOfResource::T ();
	}
}
