T::T (IO::Interface::ProtocolFactory::T * protocol_factory,
	std::string * host, std::string port,
	IO::Interface::OutputStream::T <char> * log) :
	protocol_factory (protocol_factory),
	log (log)
{
	const std::string message_prefix = "Failed to construct TCP server:\n";

	try
	{
		signal = new IO::Signal::T ();
		server_socket = new IO::ServerSocket::T (host, port, log);
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
}
