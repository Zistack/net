template <typename NonblockingInputStream>
void
T <NonblockingInputStream>::refill ()
{
	if (this -> m_eof_bit) throw Failure::EndOfResource::T ();

	try
	{
		while (true)
		{
			size_t size = this -> m_input_stream . read
			(
				this -> m_buffer,
				T::BUFFER_SIZE
			);
			if (size)
			{
				this -> m_begin = 0;
				this -> m_end = size;
				return;
			}
			Util::wait (this -> m_input_stream, this -> m_cancel_signal);
		}
	}
	catch (Failure::EndOfResource::T)
	{
		this -> m_eof_bit = true;
		throw;
	}
}
