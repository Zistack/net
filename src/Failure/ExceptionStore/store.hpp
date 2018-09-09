void
T::store (const std::exception & e)
{
	this->store (std::make_exception_ptr (e));
}

void
T::store (std::exception_ptr e)
{
	std::unique_lock<decltype (this->m)> (this->m);

	if (!this->exception) this->exception = e;
}
