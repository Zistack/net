Socket::T *
T::accept ()
{
	const std::string message_prefix = "IO::ServerSocket::accept\n";

	try
	{
		struct sockaddr peer_address;
		socklen_t address_size;

		int client_file_descriptor = accept4 (
		    this->file_descriptor, &peer_address, &address_size, SOCK_NONBLOCK);

		if (client_file_descriptor == -1)
		{
			const std::string message =
			    std::string ("accept: ") + strerror (errno) + "\n";

			switch (errno)
			{
			case EAGAIN:
			// case EWOULDBLOCK: // Apparently duplicate with EAGAIN
			case ECONNABORTED:
			case EINTR:
			case EPERM:
				throw RetryException::T (message);
			case EBADF:
			case EFAULT:
			case EINVAL:
			case EMFILE:
			case ENFILE:
			case ENOBUFS:
			case ENOMEM:
			case ENOTSOCK:
			case EOPNOTSUPP:
			case EPROTO:
			default:
				throw ResourceError::T (message);
			}
		}

		return new Socket::T (client_file_descriptor);
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
