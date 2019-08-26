template <typename Protocol>
T <Protocol>::T (std::chrono::milliseconds output_timeout, uint64_t chunk_size)
:	MessageSender::T <Interface::T <Protocol>> (chunk_size),
	m_output_timeout (output_timeout),
	m_rng (Crypto::Util::getRandom),
	m_close_bit (this -> m_close_mutex)
{
}
