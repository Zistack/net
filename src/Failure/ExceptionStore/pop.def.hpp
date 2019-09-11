void
T::pop ()
{
	std::unique_lock lock (this -> m_mutex);

	if (this -> m_exception)
	{
		std::exception_ptr e = this -> m_exception;
		this -> m_exception = nullptr;
		std::rethrow_exception (e);
	}
}
