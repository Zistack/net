int
T::newSocket (Server::Socket::T & server_socket)
{
	const std::string message_prefix =
	    "TCP::Server::Connection::Socket::T::newSocket\n";

	int file_descriptor;

	while ((file_descriptor = accept4 (server_socket.fileDescriptor (),
	            nullptr,
	            nullptr,
	            SOCK_NONBLOCK)) == -1)
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
			throw Failure::Error::T (
			    message_prefix + "accept: " + strerror (errno) + "\n");
		}
	}

	return file_descriptor;
}
