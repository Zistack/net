template <typename NonblockingInputStream>
char
T <NonblockingInputStream>::peek ()
{
	if (this -> m_begin == this -> m_end)
	{
		this -> refill ();
	}

	return this -> m_buffer [this -> m_begin];
}
