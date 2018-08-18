void
T::clean ()
{
	const std::string message_prefix = "TLS::Server::Protocol::clean\n";

	try
	{
		this->adapter->clean ();
		delete this->adapter;
		this->adapter = NULL;

		{
			IO::Signal::T signal;
			Thread::Timeout::T timeout (
			    this->timeout_ns, [&]() { signal.send (); });
			this->ssl->shutdown (signal);
		}

		delete this->ssl;
		this->ssl = NULL;
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
