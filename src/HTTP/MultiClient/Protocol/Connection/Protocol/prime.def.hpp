void
T::prime ()
{
	std::unique_lock active_lock (this -> m_active_mutex);

	this -> running = true;
}
