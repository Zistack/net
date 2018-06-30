T::T (IO::Interface::Protocol::T * protocol,
	std::string hostname,
	std::string port,
	IO::Interface::OutputStream::T <char> * log) :
	protocol (protocol),
	log (log)
{
	const std::string message_prefix = "TCP::Client::T\n";

	try
	{
		signal = new IO::Signal::T ();
		socket = new IO::Socket::T (hostname, port, log);
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
}
