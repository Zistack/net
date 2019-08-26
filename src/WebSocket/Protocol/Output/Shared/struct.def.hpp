template <typename Output>
struct T
{
	std::chrono::milliseconds
	outputTimeout () const;

	std::mutex &
	rngMutex ();

	Crypto::RNG::T &
	rng ();

	std::mutex &
	outputMutex ();
};
