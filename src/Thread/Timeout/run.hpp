void
T::run (Duration::T timeout,
    std::mutex * mutex,
    bool * cancelled,
    std::function<void(void)> callback)
{
	std::this_thread::sleep_for (timeout);

	mutex->lock ();

	if (!*cancelled)
	{
		callback ();
		*cancelled = true;
		mutex->unlock ();
		return;
	}

	mutex->unlock ();

	delete mutex;
	delete cancelled;
}
