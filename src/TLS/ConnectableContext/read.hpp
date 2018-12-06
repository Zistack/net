size_t
T::read (char * buffer, size_t count, IO::Interface::Watchable::T & signal)
{
	const std::string message_prefix = "TLS::Context::T::read\n";

	while (true)
	{
		ssize_t size = tls_read (this->tls_context.get (), buffer, count);

		if (size <= 0)
		{
			switch (size)
			{
			case TLS_WANT_POLLIN:
				IO::Util::wait (this->input, signal);
				continue;
			case TLS_WANT_POLLOUT:
				IO::Util::wait (this->output, signal);
				continue;
			default:
			case -1:
				throw Failure::Error::T (message_prefix +
				    "Failed to read from TLS context: " +
				    tls_error (this->tls_context.get ()) + "\n");
			case 0:
				throw IO::EOF::T ();
			}
		}
		else
			return (size_t) size;
	}
}
