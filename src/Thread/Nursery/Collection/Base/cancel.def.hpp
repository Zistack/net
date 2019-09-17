template <bool use_external_store, typename Cancellable>
void
T <use_external_store, Cancellable>::cancel ()
{
	std::unique_lock lock (this -> m_mutex);

	this -> m_cancelled = true;
	for (auto && [thread_id, thread] : this -> m_threads)
	{
		thread . cancel ();
	}
}
