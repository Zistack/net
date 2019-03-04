void
T::write (const char * buffer, size_t count)
{
	size_t remaining = this->vector.size () - this->pointer;

	size_t overwrite_count = count > remaining ? remaining : count;

	size_t i;

	for (i = 0; i < overwrite_count; ++i)
	{
		this->vector[this->pointer + i] = (uint8_t) buffer[i];
	}

	for (; i < count; ++i) this->vector.push_back ((uint8_t) buffer[i]);

	this->pointer += count;
}
