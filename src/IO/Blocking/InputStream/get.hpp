template <typename NonblockingInputStream>
char
T<NonblockingInputStream>::get ()
{
	if (this->begin == this->end)
	{
		while (true)
		{
			this->end = this->input_stream.read (this->buffer, T::BUFFER_SIZE);
			if (this->end) break;
			Util::wait (this->input_stream, this->cancel_signal);
		}
		this->begin = 0;
	}

	char c = this->buffer[this->begin];
	++this->begin;

	return c;
}
