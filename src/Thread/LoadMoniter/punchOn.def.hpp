void
T::punchOn ()
{
	std::unique_lock lock (this -> m_mutex);

	if (! this -> m_on)
	{
		std::chrono::time_point now = std::chrono::steady_clock::now ();

		this -> m_last_punch_on = now;
		this -> m_on = true;
	}
}
