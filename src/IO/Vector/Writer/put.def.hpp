void
T::put (char c)
{
	if (this -> m_pointer < this -> m_vector . size ())
	{
		this -> m_vector [this -> m_pointer] = (uint8_t) c;
	}
	else
	{
		this -> m_vector . push_back ((uint8_t) c);
		this -> m_pointer = this -> m_vector . size ();
	}
}
