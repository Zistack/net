void
T::handshake (IO::Interface::Watchable::T & signal)
{
	const std::string message_prefix = "TLS::Context::T::handshake\n";

	while (true)
	{
		switch (tls_handshake (this->tls_context.get ()))
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
			    "Failed to complete TLS handshake: " +
			    tls_error (this->tls_context.get ()) + "\n");
		case 0:
			return;
		}
	}
}
