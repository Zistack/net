T::T (std::chrono::nanoseconds output_timeout, uint64_t chunk_size)
:	MessageSender::T <T> (chunk_size),
	output_timeout (output_timeout),
	rng (Crypto::Util::getRandom)
{
}
