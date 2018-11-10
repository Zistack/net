template <class Function, class Cancel>
void
T::call (Function && function, Cancel && cancel)
{
	const std::string message_prefix = "Thread::Nursery::T::call\n";

	if (this->start (nullptr, std::forward<Cancel> (cancel)))
	{
		bool first_fail = false;

		std::exception_ptr e;

		try
		{
			function ();
		}
		catch (...)
		{
			e = std::current_exception ();
			first_fail = this->exception_store.store (e);
		}
		this->finish ();
		if (first_fail) this->cancel ();
		if (e) std::rethrow_exception (e);
	}
	else
	{
		throw Failure::Error::T (
		    message_prefix + "Nursery has already been cancelled\n");
	}
}