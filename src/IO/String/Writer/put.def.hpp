void
T::put (char c)
{
	if (this -> m_pointer < this -> m_string . size ())
	{
		this -> m_string [this -> m_pointer] = c;
	}
	else
	{
		this -> m_string . push_back (c);
		this -> m_pointer = this -> m_string . size ();
	}
}
