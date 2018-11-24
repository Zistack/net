void
T::write (const char * buffer, size_t count)
{
	while (true)
	{
		size_t size = this->output_stream.write (buffer, count);
		buffer += size;
		count -= size;

		if (!count) return;

		Util::wait (this->output_stream, this->cancel_signals);
	}
}
