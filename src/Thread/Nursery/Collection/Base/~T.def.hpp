template <typename Cancellable>
T <Cancellable>::~T ()
{
	std::unique_lock lock (this -> m_mutex);

	while (! this -> m_threads . empty ())
	{
		this -> m_condition_variable . wait (lock);
	}
}
