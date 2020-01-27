void
T::cancel ()
{
	std::unique_lock active_lock (this -> m_active_mutex);

	this -> running = false;

	if (this -> active)
	{
		this -> active = false;

		if (this -> primed)
		{
			this -> SimpleClientInterface::T::cancel ();
			this -> primed = false;
		}
	}

	this -> m_active_condition_variable . notify_all ();
}
