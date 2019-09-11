void
T::write (const char * buffer, size_t count)
{
	this -> m_string . replace (this -> m_pointer, count, buffer);

	this -> m_pointer += count;
}
