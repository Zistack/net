void
T::refill ()
{
	if (this -> eof_bit)
	{
		throw Failure::EndOfResource::T ();
	}

	std::unique_lock socket_lock (this -> socket_mutex);

	while (true)
	{
		ssize_t size = tls_read
		(
			this -> tls_context,
			this -> buffer . get (),
			this -> BUFFER_SIZE
		);

		if (size <= 0)
		{
			switch (size)
			{
			case TLS_WANT_POLLIN:

				IO::Util::wait (* this, this -> cancel_signal);
				continue;

			case TLS_WANT_POLLOUT:

				IO::Util::wait (* this, this -> cancel_signal);
				continue;

			case -1:
			default:

				throw Failure::Error::T
				(
					std::string ("Failed to read from TLS context: ") +
						tls_error (this->tls_context) +
						"\n"
				);

			case 0:

				this -> eof_bit = true;
				throw Failure::EndOfResource::T ();
			}
		}
		else
		{
			this -> begin = 0;
			this -> end = (size_t) size;
			return;
		}
	}
}
