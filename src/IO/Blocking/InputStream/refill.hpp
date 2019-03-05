template <typename NonblockingInputStream>
void
T<NonblockingInputStream>::refill ()
{
	if (this->eof_bit)
	{
		throw Failure::EndOfResource::T ();
	}

	try
	{
		while (true)
		{
			this->end = this->input_stream.read (this->buffer, T::BUFFER_SIZE);
			if (this->end) break;
			Util::wait (this->input_stream, this->cancel_signal);
		}
		this->begin = 0;
	}
	catch (Failure::EndOfResource::T)
	{
		this->eof_bit = true;
		throw;
	}
}
