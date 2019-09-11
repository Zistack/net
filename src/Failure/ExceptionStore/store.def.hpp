bool
T::store (const std::exception & e)
{
	return this -> store (std::make_exception_ptr (e));
}

bool
T::store (std::exception_ptr e)
{
	std::unique_lock lock (this -> m_mutex);

	if (! this -> m_exception)
	{
		this -> m_exception = e;
		return true;
	}
	else return false;
}
