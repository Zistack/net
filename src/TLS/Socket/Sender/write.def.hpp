template <typename Interface>
void
T <Interface>::write (const char * buffer, size_t count)
{
	if (this -> m_next + count >= this -> m_output_buffer_size)
	{
		this -> flush ();

		this -> send (buffer, count);
	}
	else
	{
		memcpy (this -> m_buffer . get () + this -> m_next, buffer, count);
		this -> m_next += count;
	}
}
