void
T::poll ()
{
	std::unique_lock lock (this -> m_mutex);

	if (this -> m_exception) std::rethrow_exception (this -> m_exception);
}
