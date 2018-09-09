void
T::poll ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	if (this->exception) std::rethrow_exception (this->exception);
}
