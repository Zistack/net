template <typename NonblockingOutputStream>
void
T<NonblockingOutputStream>::send (const char * buffer, size_t count)
{
	while (true)
	{
		size_t size = this -> m_output_stream . write (buffer, count);
		buffer += size;
		count -= size;

		if (! count) return;

		Util::wait (this -> m_output_stream, this -> m_cancel_signal);
	}
}
