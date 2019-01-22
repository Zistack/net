void
T::run ()
{
	const std::string message_prefix = "Socket::Server::Service::T::run\n";

	{
		SuppressingScope::T<decltype (this->shutdown_signal)>
		    shutdown_signal_scope (std::move (this->shutdown_signal_scope));

		Thread::Nursery::T nursery (this->exception_store);

		nursery.run (*this,
		    [this, &nursery]() {
			    this->listen (nursery);
			    nursery.cancel ();
		    });
	}

	try
	{
		exception_store.pop ();
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
