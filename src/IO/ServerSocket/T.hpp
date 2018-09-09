T::T (const char * host, const char * port, Interface::OutputStream::T * log)
{
	std::string message_prefix = "IO::ServerSocket::T::T\n";

	struct addrinfo hints;

	memset (&hints, 0, sizeof (hints));

	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_INET6;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	struct addrinfo * results;

	int err = getaddrinfo (host, port, &hints, &results);

	if (err)
	{
		throw Failure::Error::T (
		    message_prefix + "getaddrinfo: " + gai_strerror (err) + "\n");
	}

	struct addrinfo * p;

	for (p = results; p != nullptr; p = p->ai_next)
	{
		this->file_descriptor = socket (
		    p->ai_family, p->ai_socktype | SOCK_NONBLOCK, p->ai_protocol);

		if (this->file_descriptor == -1)
		{
			std::string message =
			    message_prefix + "socket: " + strerror (errno) + "\n";
			if (log) log->print (message);
			continue;
		}

		int yes = 1;
		if (setsockopt (this->file_descriptor,
		        SOL_SOCKET,
		        SO_REUSEADDR,
		        &yes,
		        sizeof (yes)) == -1)
		{
			std::string message =
			    message_prefix + "setsockopt: " + strerror (errno) + "\n";
			freeaddrinfo (results);
			close (this->file_descriptor);
			throw Failure::Error::T (message);
		}

		if (bind (this->file_descriptor, p->ai_addr, p->ai_addrlen) == -1)
		{
			std::string message =
			    std::string ("bind: ") + strerror (errno) + "\n";
			close (this->file_descriptor);
			if (log) log->print (message);
			continue;
		}

		break;
	}

	freeaddrinfo (results);

	if (!p)
	{
		throw Failure::Error::T ("No valid addresses\n");
	}

	if (listen (this->file_descriptor, SOMAXCONN) == -1)
	{
		std::string message =
		    message_prefix + "listen: " + strerror (errno) + "\n";
		close (this->file_descriptor);
		throw Failure::Error::T (message);
	}
}
