Socket::T *
T::accept ()
{
	const std::string message_prefix = "IO::ServerSocket::T::accept\n";

	int client_file_descriptor;

	while ((client_file_descriptor = accept4 (
	            this->file_descriptor, nullptr, nullptr, SOCK_NONBLOCK)) == -1)
	{
		switch (errno)
		{
		case EAGAIN:
#if EWOULDBLOCK != EAGAIN
		case EWOULDBLOCK:
#endif
		case ECONNABORTED:
		case EINTR:
		case EPERM:
			continue;
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
			throw Failure::Error::T (
			    message_prefix + "accept: " + strerror (errno) + "\n");
		}
	}

	return new Socket::T (client_file_descriptor);
}
