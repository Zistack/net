bool
T::write (char * buffer, size_t count, IO::Signal::T & signal)
{
	const std::string message_prefix = "TLS::Context::T::write\n";

	bool needed_read = false;

	while (count)
	{
		ssize_t size = tls_write (this->tls_context.get (), buffer, count);

		if (size < 0)
		{
			switch (size)
			{
			case TLS_WANT_POLLIN:
				needed_read = true;
				IO::Util::wait (this->input, signal);
				continue;
			case TLS_WANT_POLLOUT:
				IO::Util::wait (this->output, signal);
				continue;
			default:
			case -1:
				throw Failure::Error::T (message_prefix +
				    "Failed to write to TLS context: " +
				    tls_error (this->tls_context.get ()) + "\n");
			}
		}
		else
		{
			buffer += size;
			count -= (size_t) size;
		}
	}

	return needed_read;
}
