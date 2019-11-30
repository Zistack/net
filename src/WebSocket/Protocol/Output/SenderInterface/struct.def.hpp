struct T : MessageSender::T <T>, PingPongSender::T <T>
{
	T (std::chrono::nanoseconds output_timeout, uint64_t chunk_size);

	~T () = default;

	// Given members

	std::chrono::nanoseconds output_timeout;

	// Internal members

	std::mutex rng_mutex;
	Crypto::RNG::T rng;

	std::mutex output_mutex;
};
