char
T::get ()
{
	if (start == end)
	{
		while (true)
		{
			this->end = this->input_stream.read (this->buffer, T::BUF_SIZE);
			if (this->end) break;
			Util::wait (this->input_stream, this->cancel_signal);
		}
		this->start = 0;
	}

	char c = this->buffer[start];
	++start;

	return c;
}
