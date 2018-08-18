void
T::shutdown (IO::Signal::T & signal)
{
	const std::string message_prefix = "TLS::SSL::shutdown\n";

	try
	{
		std::unique_lock<T> (*this);

		while (true)
		{
			this->mutex.lock ();
			int ret = SSL_shutdown (this->ssl);
			this->mutex.unlock ();

			if (ret < 0)
			{
				this->mutex.lock ();
				int ssl_error = SSL_get_error (this->ssl, ret);
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
			else if (ret == 0)
				continue;
			else if (ret == 1)
				return;
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
