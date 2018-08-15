T::T (IO::Interface::Protocol::T & protocol,
    std::string hostname,
    std::string port,
    IO::Interface::OutputStream::T * log) :
    protocol (protocol),
    log (log)
{
	const std::string message_prefix = "TCP::Client::T\n";

	try
	{
		signal = new IO::Signal::T ();
		socket = new IO::Socket::T (hostname, port, log);
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
