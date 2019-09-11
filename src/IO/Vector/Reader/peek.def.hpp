char
T::peek ()
{
	if (this -> m_pointer < this -> m_vector . size ())
	{
		return (char) this -> m_vector [this -> m_pointer];
	}
	else
	{
		throw Failure::EndOfResource::T ();
	}
}
