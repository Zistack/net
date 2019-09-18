template <bool use_external_store, typename Cancellable>
T <use_external_store, Cancellable>::~T ()
{
	std::unique_lock lock (this -> m_mutex);

	while (! this -> m_threads . empty ())
	{
		this -> m_condition_variable . wait (lock);
	}

	if constexpr (! use_external_store) this -> m_exception_store . poll ();
}
