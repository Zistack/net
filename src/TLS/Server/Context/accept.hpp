std::unique_ptr<Connection::Context::T>
T::accept (IO::Interface::NonblockingInputStream::T * input,
    IO::Interface::NonblockingOutputStream::T * output,
    IO::Signal::T & signal)
{
	return std::make_unique<Connection::Context::T> (
	    *this, input, output, signal);
}

struct tls *
T::accept (IO::Interface::NonblockingInputStream::T * input,
    IO::Interface::NonblockingOutputStream::T * output)
{
	const std::string message_prefix = "TLS::Server::Context::T::accept\n";

	struct tls * client_context = nullptr;

	if (tls_accept_fds (this->tls_context.get (),
	        &client_context,
	        input->fileDescriptor (),
	        output->fileDescriptor ()))
	{
		throw Failure::Error::T (message_prefix +
		    "Failed to establish TLS connection: " +
		    tls_error (this->tls_context.get ()) + "\n");
	}

	return client_context;
}
