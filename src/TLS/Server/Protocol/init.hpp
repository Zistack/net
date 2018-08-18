void
T::init (IO::Interface::NonblockingInputStream::T & input_stream,
    IO::Interface::NonblockingOutputStream::T & output_stream)
{
	const std::string message_prefix = "TLS::Server::Protocol::init\n";

	try
	{
		this->ssl = new SSL::T (this->context, input_stream, output_stream);

		{
			IO::Signal::T signal;
			Thread::Timeout::T timeout (
			    this->timeout_ns, [&]() { signal.send (); });
			this->ssl->accept (signal);
		}

		this->adapter =
		    new Adapter::T (*this->ssl, *this->protocol, this->timeout_ns);
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
