template <typename Interface, typename Specialization>
template <typename CancelSignal>
void
T <Interface, Specialization>::handshake (CancelSignal && cancel_signal)
{
	while (true)
	{
		int dir;
		gnutls_alert_description_t alert;

		int err = gnutls_handshake (this -> session);
		switch (err)
		{
		case GNUTLS_E_SUCCESS:

			return;

		case GNUTLS_E_AGAIN:
		case GNUTLS_E_INTERRUPTED:

			// man gnutls_record_get_direction
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

		case GNUTLS_E_GOT_APPLICATION_DATA:

			// I assume that the data ends up in the gnutls input buffer, though
			// the documentation doesn't really say.  We're just gonna retry,
			// since this isn't a fatal error.
			continue;

		case GNUTLS_E_WARNING_ALERT_RECEIVED:

//			alert = gnutls_alert_get (this -> m_session);

			// Then what?  Presumably, we could log it, but for now we will
			// ignore it.
			continue;

		case GNUTLS_E_FATAL_ALERT_RECEIVED:

			alert = gnutls_alert_get (this -> session);

			throw Failure::Error::T
			(
				std::string ("Failed to complete TLS handshake: ") +
					gnutls_strerror (err) +
					gnutls_alert_get_name (alert) +
					"\n"
			);

		default:

			throw Failure::Error::T
			(
				std::string ("Failed to complete TLS handshake: ") +
					gnutls_strerror (err) +
					"\n"
			);
		}
	}
}
