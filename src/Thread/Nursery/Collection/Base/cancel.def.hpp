template <typename Cancellable>
void
T <Cancellable>::cancel ()
{
	std::unique_lock lock (this -> m_mutex);

	this -> m_cancelled = true;
	for (auto && [thread_id, thread] : this -> m_threads)
	{
		thread . cancel ();
	}
}
