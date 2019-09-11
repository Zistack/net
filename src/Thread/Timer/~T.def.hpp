T::~T ()
{
	{
		std::unique_lock lock (this -> m_mutex);

		this -> m_stop = true;
		this -> m_condition_variable . notify_one ();
	}

	this -> m_thread . join ();
}
