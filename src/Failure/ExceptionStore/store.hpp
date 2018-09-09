bool
T::store (const std::exception & e)
{
	return this->store (std::make_exception_ptr (e));
}

bool
T::store (std::exception_ptr e)
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	if (!this->exception)
	{
		this->exception = e;
		return true;
	}
	return false;
}
