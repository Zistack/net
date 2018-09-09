struct T
{
	template <class Rep, class Period>
	T (const std::chrono::duration<Rep, Period> timeout,
	    std::function<void(void)> callback);

	~T ();

	template <class Rep, class Period>
	static void
	run (T * timer,
	    std::chrono::duration<Rep, Period> timeout,
	    std::function<void(void)> callback);

	bool stop;
	std::mutex m;
	std::condition_variable c;
	std::thread thread;
};
