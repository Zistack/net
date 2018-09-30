void
T::run ()
{
	const std::string message_prefix = "TCP::Client::T::run\n";

	try
	{
		IO::Socket::T socket (this->hostname, this->port, this->log);

		this->protocol->run (socket.input_stream, socket.output_stream);
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
