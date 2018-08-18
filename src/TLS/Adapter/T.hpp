T::T (SSL::T & ssl,
    IO::Interface::Protocol::T & protocol,
    uint64_t timeout_ns) :
    ssl (ssl),
    protocol (protocol),
    nursery (this->exception_store)
{
	const std::string message_prefix = "TLS::Adapter::T\n";

	try
	{
		this->socket_to_protocol = new IO::Pipe::T ();
		this->input_timeout_signal = new IO::Signal::T ();

		this->protocol_output_stream = new IO::Blocking::OutputStream::T (
		    this->socket_to_protocol->output_stream,
		    *this->input_timeout_signal);

		this->protocol_to_socket = new IO::Pipe::T ();
		this->output_timeout_signal = new IO::Signal::T ();
		this->shutdown_signal = new IO::Signal::T ();

		this->nursery.add (&T::runProtocol, this);
		this->nursery.add (&T::runOutputDump, this);
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
