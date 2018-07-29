void
T::write (char * buffer, size_t count)
{
	do
	{
		Util::wait (this->output_stream, this->signal);
		size_t written = this->output_stream.write (buffer, count);
		buffer += written;
		count -= written;
	} while (count);
}
