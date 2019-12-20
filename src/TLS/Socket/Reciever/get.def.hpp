template <typename Interface>
char
T <Interface>::get ()
{
	if (this -> m_begin == this -> m_end)
	{
		this -> refill ();
	}

	char c = this -> m_buffer [this -> m_begin];
	++ this -> m_begin;

	return c;
}
