template <typename Output>
struct T
{
	std::chrono::milliseconds
	outputTimeout () const;

	std::mutex &
	outputMutex ();
};
