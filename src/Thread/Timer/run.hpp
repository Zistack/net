template <class Rep, class Period>
void
T::run (T * timer,
    std::chrono::duration<Rep, Period> timeout,
    std::function<void(void)> callback)
{
	auto now = std::chrono::steady_clock::now ();
	auto timeout_point = now + timeout;
	std::unique_lock<decltype (timer->m)> lock (timer->m);

	while (!timer->stop && std::chrono::steady_clock::now () < timeout_point)
	{
		timer->c.wait_until (lock, timeout_point);
	}

	if (!timer->stop) callback ();
}
