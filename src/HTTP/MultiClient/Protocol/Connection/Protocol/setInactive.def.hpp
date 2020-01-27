void
T::setInactive ()
{
	std::unique_lock active_lock (this -> m_active_mutex);

	this -> active = false;

	this -> SimpleClientInterface::T::stop ();
	this -> primed = false;
}
