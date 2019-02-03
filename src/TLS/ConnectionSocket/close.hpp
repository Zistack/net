void
T::close (IO::Interface::Watchable::T & cancel_signal)
{
	while (true)
	{
		switch (tls_close (this->tls_context.get ()))
		{
		case TLS_WANT_POLLIN:
			IO::Util::wait (this->input_strem, signal);
			continue;
		case TLS_WANT_POLLOUT:
			IO::Util::wait (this->output_stream, signal);
			continue;
		default:
		case -1:
			throw Failure::Error::T (
			    std::string ("Faled to close TLS connection: ") +
			    tls_error (this->tls_context.get ()) + "\n");
		case 0:
			return;
		}
	}
}
