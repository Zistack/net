template <typename NonblockingOutputStream>
void
T <NonblockingOutputStream>::write (const char * buffer, size_t count)
{
	if (this -> m_next + count >= BUFFER_SIZE)
	{
		this -> flush ();

		this -> send (buffer, count);
	}
	else
	{
		memcpy (this -> m_buffer + this -> m_next, buffer, count);
		this -> m_next += count;
	}
}
