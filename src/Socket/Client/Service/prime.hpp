void
T::prime ()
{
	const std::string message_prefix = "Socket::Client::Service::T::prime\n";

	try
	{
		std::unique_ptr<IO::Interface::Socket::T> socket = this->newSocket ();

		this->client_protocol.prime (
		    socket->inputStream (), socket->outputStream ());

		this->socket = std::move (socket);
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
