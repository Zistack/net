template <typename CancelSignal>
void
T::close (CancelSignal && cancel_signal)
{
	while (true)
	{
		switch (tls_close (this -> m_tls_context . get ()))
		{
		case TLS_WANT_POLLIN:

			IO::Util::wait
			(
				this -> input (),
				std::forward <CancelSignal> (cancel_signal)
			);
			continue;

		case TLS_WANT_POLLOUT:

			IO::Util::wait
			(
				this -> output (),
				std::forward <CancelSignal> (cancel_signal)
			);
			continue;

		default:
		case -1:

			throw Failure::Error::T
			(
				std::string ("Faled to close TLS connection: ") +
					tls_error (this -> m_tls_context . get ()) +
					"\n"
			);

		case 0:

			return;
		}
	}
}
