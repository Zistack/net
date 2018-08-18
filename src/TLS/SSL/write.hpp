void
T::write (char * buffer, int count, IO::Signal::T & signal)
{
	const std::string message_prefix = "TLS::SSL::write\n";

	try
	{
		std::unique_lock<T> (*this);

		while (count)
		{
			this->mutex.lock ();
			int size = SSL_write (this->ssl, buffer, count);
			this->mutex.unlock ();

			if (size <= 0)
			{
				this->mutex.lock ();
				int ssl_error = SSL_get_error (this->ssl, size);
				this->mutex.unlock ();

				switch (ssl_error)
				{
				case SSL_ERROR_WANT_READ:
					IO::Util::wait (this->input, signal);
					continue;
				case SSL_ERROR_WANT_WRITE:
					IO::Util::wait (this->output, signal);
					continue;
				case SSL_ERROR_ZERO_RETURN:
				case SSL_ERROR_SYSCALL:
				case SSL_ERROR_SSL:
				default:
					throw ProtocolError::T (getErrorMessage ());
				}
			}
			else
			{
				buffer += size;
				size -= count;
			}
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
