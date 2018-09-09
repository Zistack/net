T::T (IO::Interface::Protocol::T * protocol,
    const char * hostname,
    const char * port,
    IO::Interface::OutputStream::T * log) :
    protocol (protocol),
    log (log)
{
	const std::string message_prefix = "TCP::Client::T::T\n";

	try
	{
		signal = new IO::Signal::T ();
		socket = new IO::Socket::T (hostname, port, log);
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
