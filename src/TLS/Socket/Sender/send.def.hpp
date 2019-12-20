template <typename Interface>
void
T <Interface>::send (const char * buffer, size_t count)
{
	std::unique_lock write_lock (this -> interface () . write_mutex);

	while (count)
	{
		ssize_t size = gnutls_record_send
		(
			this -> interface () . session,
			buffer,
			count
		);

		if (size < 0)
		{
			switch (size)
			{
			case GNUTLS_E_AGAIN:
			case GNUTLS_E_INTERRUPTED:

				IO::Util::wait (* this, this -> m_cancel_signal);
				continue;

			default:

				throw Failure::ResourceError::T
				(
					std::string ("Failed to write to TLS connection: ") +
						gnutls_strerror ((int) size) +
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
