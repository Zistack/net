template <typename Interface, typename Specialization>
template <typename CancelSignal>
void
T <Interface, Specialization>::close (CancelSignal && cancel_signal)
{
	while (true)
	{
		int dir;

		int err = gnutls_bye (this -> session, GNUTLS_SHUT_RDWR);
		switch (err)
		{
		case GNUTLS_E_SUCCESS:

			return;

		case GNUTLS_E_AGAIN:
		case GNUTLS_E_INTERRUPTED:

			dir = gnutls_record_get_direction (this -> session);
			if (dir == 0 /* read */)
			{
				IO::Util::wait
				(
					this -> interface () . reciever (),
					cancel_signal
				);
				continue;
			}
			else // dir == 1 /* write */
			{
				IO::Util::wait
				(
					this -> interface () . sender (),
					cancel_signal
				);
				continue;
			}

		default:

			throw Failure::Error::T
			(
				std::string ("Faled to close TLS connection: ") +
					gnutls_strerror (err) +
					"\n"
			);
		}
	}
}
