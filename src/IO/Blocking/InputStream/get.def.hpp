template <typename NonblockingInputStream>
char
T <NonblockingInputStream>::get ()
{
	if (this -> m_begin == this -> m_end)
	{
		this -> refill ();
	}

	char c = this -> m_buffer [this -> m_begin];
	++ this -> m_begin;

	return c;
}
