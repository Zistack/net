template <typename Interface>
void
T <Interface>::put (char c)
{
	this -> m_buffer [this -> m_next] = c;
	++ this -> m_next;

	if (this -> m_next == this -> m_output_buffer_size)
	{
		this -> flush ();
	}
}
