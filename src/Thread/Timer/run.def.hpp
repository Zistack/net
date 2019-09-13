template
<
	typename Rep,
	typename Period,
	typename Callback,
	typename ... CallbackArgs
>
void
T::run
(
	T & timer,
	std::chrono::duration <Rep, Period> timeout,
	Callback && callback,
	CallbackArgs && ... callback_args
)
{
	auto now = std::chrono::steady_clock::now ();
	auto timeout_point = now + timeout;
	std::unique_lock lock (timer . m_mutex);

	while (! timer . m_stop && std::chrono::steady_clock::now () < timeout_point)
	{
		timer . m_condition_variable . wait_until (lock, timeout_point);
	}

	if (! timer . m_stop)
	{
		callback (std::forward <CallbackArgs> (callback_args) ...);
	}
}
