void
T::prime ()
{
	const std::string message_prefix = "Socket::Server::Service::T::prime\n";

	try
	{
		this->server_socket = this->newServerSocket ();
		this->shutdown_signal_scope =
		    SuppressingScope::T<decltype (this->shutdown_signal)> (
		        this->shutdown_signal, this->exception_store);
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
