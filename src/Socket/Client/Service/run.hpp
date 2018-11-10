void
T::run ()
{
	const std::string message_prefix = "Socket::Client::Service::T::run\n";

	std::unique_ptr<IO::Interface::Socket::T> socket (std::move (this->socket));

	try
	{
		this->client_protocol.run ();
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
