struct tls *
T::newConnection (IO::Interface::NonblockingInputStream::T & input,
    IO::Interface::NonblockingOutputStream::T & output)
{
	const std::string message_prefix =
	    "TLS::Server::Context::T::newConnection\n";

	struct tls * client_context = nullptr;

	if (tls_accept_fds (this->tls_context.get (),
	        &client_context,
	        input.fileDescriptor (),
	        output.fileDescriptor ()))
	{
		throw Failure::Error::T (message_prefix +
		    "Failed to establish TLS connection: " +
		    tls_error (this->tls_context.get ()) + "\n");
	}

	return client_context;
}
