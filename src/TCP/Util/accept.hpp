int
accept (int server_socket)
{
	const std::string message_prefix = "Failed to accept TCP connection:\n";

	int connection_socket;

	while ((connection_socket = accept4 (
	            server_socket, nullptr, nullptr, SOCK_NONBLOCK)) == -1)
	{
		switch (errno)
		{
		case EAGAIN:
#if EWOULDBLOCK != EAGAIN
		case EWOULDBLOCK:
#endif
		case EINTR:
			continue;
		case ECONNABORTED:
			throw AbortedException::T ();
		default:
			throw Failure::ResourceError::T (
			    message_prefix + "accept4: " + strerror (errno) + "\n");
		}
	}

	return connection_socket;
}
