int
T::compare (const T & other) const
{
	size_t i;
	for (i = 0; i < this -> m_octets . size (); ++ i)
	{
		if (this -> m_octets [i] < other . m_octets [i]) return -1;
		if (this -> m_octets [i] > other . m_octets [i]) return 1;
	}

	return 0;
}
