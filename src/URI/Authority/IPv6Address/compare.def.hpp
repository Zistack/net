int
T::compare (const T & other) const
{
	size_t i;
	for (i = 0; i < this -> m_hexadecitets . size (); ++ i)
	{
		if (this -> m_hexadecitets [i] < other . m_hexadecitets [i]) return -1;
		if (this -> m_hexadecitets [i] > other . m_hexadecitets [i]) return 1;
	}

	return 0;
}
