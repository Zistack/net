template <typename Cancellable,
    typename Function,
    typename... Arguments,
    typename>
void
T::call (Cancellable & cancellable,
    Function && function,
    Arguments &&... arguments)
{
	this->call (&cancellable,
	    std::forward<Function> (function),
	    std::forward<Arguments> (arguments)...);
}

template <typename Function, typename... Arguments, typename>
void
T::call (Function && function, Arguments &&... arguments)
{
	this->call (nullptr,
	    std::forward<Function> (function),
	    std::forward<Arguments> (arguments)...);
}

template <typename Cancellable,
    typename Function,
    typename... Arguments,
    typename>
void
T::call (Cancellable * cancellable,
    Function && function,
    Arguments &&... arguments)
{
	const std::string message_prefix = "Thread::Nursery::T::call\n";

	if (this->start (cancellable, nullptr))
	{
		bool first_fail = false;

		std::exception_ptr e;

		try
		{
			function (std::forward<Arguments> (arguments)...);
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
