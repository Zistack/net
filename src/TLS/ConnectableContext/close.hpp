void
T::close (IO::Signal::T & signal)
{
	const std::string message_prefix = "TLS::Context::T::close\n";

	while (true)
	{
		switch (tls_close (this->tls_context.get ()))
		{
		case TLS_WANT_POLLIN:
			IO::Util::wait (this->input, &signal);
			continue;
		case TLS_WANT_POLLOUT:
			IO::Util::wait (this->output, &signal);
			continue;
		default:
		case -1:
			throw Failure::Error::T (message_prefix +
			    "Faled to close TLS connection: " +
			    tls_error (this->tls_context.get ()) + "\n");
		case 0:
			return;
		}
	}
}
