char
T::get ()
{
	if (start == end)
	{
		do
		{
			Util::wait (this->input_stream, this->signal);
			this->end = this->input_stream.read (this->buffer, T::BUF_SIZE);
		} while (this->end == 0);
		this->start = 0;
	}

	char c = this->buffer[start];
	++start;

	return c;
}
