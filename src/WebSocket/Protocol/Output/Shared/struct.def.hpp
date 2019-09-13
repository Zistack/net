template <typename Output>
struct T
{
	std::chrono::nanoseconds
	outputTimeout () const;

	std::mutex &
	rngMutex ();

	Crypto::RNG::T &
	rng ();

	std::mutex &
	outputMutex ();
};
