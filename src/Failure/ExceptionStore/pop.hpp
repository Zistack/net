void
T::pop ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	if (this->exception)
	{
		std::exception_ptr e = this->exception;
		this->exception = nullptr;
		std::rethrow_exception (e);
	}
}
