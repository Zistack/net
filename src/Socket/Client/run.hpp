void
T::run ()
{
	const std::string message_prefix = "Socket::Client::T::run\n";

	try
	{
		IO::Interface::ClientSocket::T * socket = this->newSocket ();
		Failure::CleanupAction::T cleanup ([socket]() { delete socket; });

		this->protocol->run (socket->inputStream (), socket->outputStream ());
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
