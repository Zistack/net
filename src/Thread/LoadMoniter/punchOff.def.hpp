void
T::punchOff ()
{
	std::unique_lock lock (this -> m_mutex);

	if (this -> m_on)
	{
		std::chrono::time_point now = std::chrono::steady_clock::now ();

		this -> m_time_on_since_last_reset += now - this -> m_last_punch_on;
		this -> m_on = false;
	}
}
