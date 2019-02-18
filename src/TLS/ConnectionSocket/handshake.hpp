void
T::handshake (IO::Interface::Watchable::T & cancel_signal)
{
	while (true)
	{
		switch (tls_handshake (this->tls_context.get ()))
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
			    std::string ("Failed to complete TLS handshake: ") +
			    tls_error (this->tls_context.get ()) + "\n");
		case 0:
			return;
		}
	}
}
