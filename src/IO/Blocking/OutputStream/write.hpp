void
T::write (char * buffer, size_t count)
{
	while (true)
	{
		size_t written = this->output_stream.write (buffer, count);
		buffer += written;
		count -= written;

		if (!count) return;

		Util::wait (this->output_stream, this->signal);
	}
}
