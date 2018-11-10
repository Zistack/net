void
T::connect (const std::string & server_name, IO::Signal::T & signal)
{
	const std::string message_prefix = "TLS::Client::Context::T::connect\n";

	if (tls_connect_fds (this->tls_context.get (),
	        this->input.fileDescriptor (),
	        this->output.fileDescriptor (),
	        server_name.data ()))
	{
		throw Failure::Error::T (message_prefix +
		    "Failed to establish TLS connection: " +
		    tls_error (this->tls_context.get ()) + "\n");
	}

	this->handshake (signal);
}
