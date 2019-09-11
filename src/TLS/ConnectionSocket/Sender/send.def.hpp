void
T::send (const char * buffer, size_t count)
{
	std::unique_lock socket_lock (this -> m_socket_mutex);

	while (count)
	{
		ssize_t size = tls_write (this -> m_tls_context, buffer, count);

		if (size < 0)
		{
			switch (size)
			{
			case TLS_WANT_POLLIN:

				this -> m_spurious_read = true;
				IO::Util::wait (* this, this -> m_cancel_signal);
				continue;

			case TLS_WANT_POLLOUT:

				IO::Util::wait (* this, this -> m_cancel_signal);
				continue;

			default:
			case -1:

				throw Failure::ResourceError::T
				(
					std::string ("Failed to write to TLS context: ") +
						tls_error (this -> m_tls_context) +
						"\n"
				);
			}
		}
		else
		{
			buffer += size;
			count -= (size_t) size;
		}
	}
}
