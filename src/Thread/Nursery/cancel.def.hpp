void
T::cancel () noexcept
{
	std::unique_lock lock (this -> m_mutex);

	this -> m_cancelled = true;

	for (auto && [id, thread] : this -> m_threads) thread . cancel ();
}
