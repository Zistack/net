void
T::put (char c)
{
	this -> m_buffer [this -> m_next] = c;
	++ this -> m_next;

	if (this -> m_next == BUFFER_SIZE)
	{
		this -> flush ();
	}
}
