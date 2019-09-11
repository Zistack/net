void
T::refill ()
{
	if (this -> m_eof_bit)
	{
		throw Failure::EndOfResource::T ();
	}

	std::unique_lock socket_lock (this -> m_socket_mutex);

	while (true)
	{
		ssize_t size = tls_read
		(
			this -> m_tls_context,
			this -> m_buffer . get (),
			BUFFER_SIZE
		);

		if (size <= 0)
		{
			switch (size)
			{
			case TLS_WANT_POLLIN:

				IO::Util::wait (* this, this -> m_cancel_signal);
				continue;

			case TLS_WANT_POLLOUT:

				IO::Util::wait (* this, this -> m_cancel_signal);
				continue;

			case -1:
			default:

				throw Failure::Error::T
				(
					std::string ("Failed to read from TLS context: ") +
						tls_error (this -> m_tls_context) +
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
