void
T::finish () noexcept
{
	std::thread::id this_thread_id = std::this_thread::get_id ();

	std::unique_lock lock (this -> m_mutex);

	Thread::T this_thread = std::move (this -> m_threads . at (this_thread_id));
	this -> m_threads . erase (this_thread_id);

	if (this -> m_threads . empty ())
	{
		this -> m_condition_variable . notify_all ();
	}
}
