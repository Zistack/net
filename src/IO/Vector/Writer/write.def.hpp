void
T::write (const char * buffer, size_t count)
{
	size_t remaining = this -> m_vector . size () - this -> m_pointer;

	size_t overwrite_count = count > remaining ? remaining : count;

	size_t i;

	for (i = 0; i < overwrite_count; ++i)
	{
		this -> m_vector [this -> m_pointer + i] = (uint8_t) buffer [i];
	}

	for (; i < count; ++i) this -> m_vector . push_back ((uint8_t) buffer [i]);

	this -> m_pointer += count;
}
