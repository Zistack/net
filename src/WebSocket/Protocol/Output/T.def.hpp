T::T (std::chrono::nanoseconds output_timeout, uint64_t chunk_size)
:	SenderInterface::T (output_timeout, chunk_size),
	m_close_bit (this -> m_close_mutex)
{
}
