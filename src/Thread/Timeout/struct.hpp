struct T
{
	T (uint64_t nanoseconds, std::function<void(void)> callback);

	static void
	fire (union sigval arg);

	~T ();

	std::function<void(void)> callback;
	timer_t timer_id;
};
