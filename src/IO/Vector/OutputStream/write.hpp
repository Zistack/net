void
T::write (const char * buffer, size_t count)
{
	size_t i;
	for (i = 0; i < count; ++i) this->put (buffer[i]);
}
