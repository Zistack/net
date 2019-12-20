template <typename Interface>
void
T <Interface>::refill ()
{
	if (this -> m_eof_bit)
	{
		throw Failure::EndOfResource::T ();
	}

	while (true)
	{
		ssize_t size = gnutls_record_recv
		(
			this -> interface () . session,
			this -> m_buffer . get (),
			this -> m_input_buffer_size
		);

		if (size <= 0)
		{
			gnutls_alert_description_t alert;

			switch (size)
			{
			case GNUTLS_E_AGAIN:
			case GNUTLS_E_INTERRUPTED:

				if
				(
					! gnutls_record_check_pending
					(
						this -> interface () . session
					)
				)
				{
					IO::Util::wait (* this, this -> m_cancel_signal);
				}
				continue;

			case GNUTLS_E_REHANDSHAKE:

				{
					std::unique_lock write_lock
					(
						this -> interface () . write_mutex
					);

					this -> interface () . handshake (this -> m_cancel_signal);
				}

			case GNUTLS_E_FATAL_ALERT_RECEIVED:

				alert = gnutls_alert_get (this -> interface () . session);

				throw Failure::Error::T
				(
					std::string ("Failed to read from TLS connection: ") +
						gnutls_strerror (size) +
						gnutls_alert_get_name (alert) +
						"\n"
				);

			default:

				throw Failure::Error::T
				(
					std::string ("Failed to read from TLS connection: ") +
						gnutls_strerror ((int) size) +
						"\n"
				);

			case 0:

				this -> m_eof_bit = true;
				throw Failure::EndOfResource::T ();
			}
		}
		else
		{
			this -> m_begin = 0;
			this -> m_end = (size_t) size;
			return;
		}
	}
}
