double
T::updateLoad ()
{
	std::unique_lock lock (this -> m_mutex);

	std::chrono::time_point now = std::chrono::steady_clock::now ();

	std::chrono::steady_clock::duration time_on_since_last_reset =
		this -> m_time_on_since_last_reset;

	if (this -> m_on)
	{
		time_on_since_last_reset += (now - this -> m_last_punch_on);
	}

	double load = time_on_since_last_reset / (now - this -> m_last_reset);
	this -> m_load . store (load);

	this -> m_last_reset = now;
	if (this -> m_on) this -> m_last_punch_on = now;
	this -> m_time_on_since_last_reset =
		std::chrono::steady_clock::duration (0);

	return load;
}
