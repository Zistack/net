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
			size_t size =
			    this->input_stream.read (this->buffer, T::BUFFER_SIZE);
			if (size)
			{
				this->begin = 0;
				this->end = size;
				return;
			}
			Util::wait (this->input_stream, this->cancel_signal);
		}
	}
	catch (Failure::EndOfResource::T)
	{
		this->eof_bit = true;
		throw;
	}
}
