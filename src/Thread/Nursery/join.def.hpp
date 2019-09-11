void
T::join ()
{
	std::unique_lock lock (this -> m_mutex);

	while (! this -> m_threads . empty ())
	{
		this -> m_condition_variable . wait (lock);
	}

	if (this -> m_internal_store) this -> m_internal_store -> poll ();
}
