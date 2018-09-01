T::T (IO::Interface::ProtocolFactory::T & protocol_factory,
    const char * hostname,
    const char * port,
    IO::Interface::OutputStream::T * log) :
    protocol_factory (protocol_factory),
    log (log)
{
	const std::string message_prefix = "TCP::Server::T::T\n";

	try
	{
		signal = new IO::Signal::T ();
		server_socket = new IO::ServerSocket::T (hostname, port, log);
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
