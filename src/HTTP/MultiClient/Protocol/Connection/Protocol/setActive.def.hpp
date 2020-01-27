void
T::setActive ()
{
	std::unique_lock active_lock (this -> m_active_mutex);

	this -> active = true;

	this -> m_active_condition_variable . notify_all ();
}
