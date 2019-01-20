struct T
{
	template <class Rep, class Period, class Callback, class... CallbackArgs>
	T (const std::chrono::duration<Rep, Period> timeout,
	    Callback && callback,
	    CallbackArgs &&... callback_args);

	~T ();

	template <class Rep, class Period, class Callback, class... CallbackArgs>
	static void
	run (T * timer,
	    std::chrono::duration<Rep, Period> timeout,
	    Callback && callback,
	    CallbackArgs &&... callback_args);

	bool stop;
	std::mutex m;
	std::condition_variable c;
	std::thread thread;
};
