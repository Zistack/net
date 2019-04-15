T::T
(
	std::chrono::milliseconds output_timeout,
	Thread::SleepMutex::T & output_mutex
)
:	output_timeout (output_timeout), output_mutex (output_mutex)
{
}
