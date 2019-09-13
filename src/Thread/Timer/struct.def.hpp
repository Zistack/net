struct T
{
	template
	<
		typename Rep,
		typename Period,
		typename Callback,
		typename ... CallbackArgs
	>
	T
	(
		const std::chrono::duration <Rep, Period> timeout,
		Callback && callback,
		CallbackArgs && ... callback_args
	);

	~T ();

	template
	<
		typename Rep,
		typename Period,
		typename Callback,
		typename ... CallbackArgs
	>
	static void
	run
	(
		T & timer,
		std::chrono::duration <Rep, Period> timeout,
		Callback && callback,
		CallbackArgs && ... callback_args
	);

private:

	bool m_stop;
	std::mutex m_mutex;
	std::condition_variable m_condition_variable;
	std::thread m_thread;
};
