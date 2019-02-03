size_t
T::read (char * buffer,
    size_t count,
    IO::Interface::Watchable::T & cancel_signal)
{
	while (true)
	{
		ssize_t size = tls_read (this->tls_context.get (), buffer, count);

		if (size <= 0)
		{
			switch (size)
			{
			case TLS_WANT_POLLIN:
				IO::Util::wait (this->input_stream, cancel_signal);
				continue;
			case TLS_WANT_POLLOUT:
				IO::Util::wait (this->output_stream, cancel_signal);
				continue;
			default:
			case -1:
				throw Failure::Error::T (
				    std::string ("Failed to read from TLS context: ") +
				    tls_error (this->tls_context.get ()) + "\n");
			case 0:
				throw Failure::EndOfResource::T ();
			}
		}
		else
			return (size_t) size;
	}
}
