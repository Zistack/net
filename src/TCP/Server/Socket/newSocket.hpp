int
T::newSocket (const Config::T & config)
{
	std::string message_prefix = "TCP::Server::Socket::T::newSocket\n";

	struct addrinfo hints;

	memset (&hints, 0, sizeof (hints));

	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_INET6;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	struct addrinfo * results;

	int err = getaddrinfo (config.hostname, config.port, &hints, &results);

	if (err)
	{
		throw Failure::Error::T (
		    message_prefix + "getaddrinfo: " + gai_strerror (err) + "\n");
	}

	int file_descriptor;

	struct addrinfo * p;
	for (p = results; p != nullptr; p = p->ai_next)
	{
		file_descriptor = socket (
		    p->ai_family, p->ai_socktype | SOCK_NONBLOCK, p->ai_protocol);

		if (file_descriptor == -1)
		{
			// We might want to report this someday.
			continue;
		}

		int yes = 1;
		if (setsockopt (file_descriptor,
		        SOL_SOCKET,
		        SO_REUSEADDR,
		        &yes,
		        sizeof (yes)) == -1)
		{
			std::string message =
			    message_prefix + "setsockopt: " + strerror (errno) + "\n";
			freeaddrinfo (results);
			close (file_descriptor);
			throw Failure::Error::T (message);
		}

		if (bind (file_descriptor, p->ai_addr, p->ai_addrlen) == -1)
		{
			close (file_descriptor);
			// We might want to report this someday.
			continue;
		}

		break;
	}

	freeaddrinfo (results);

	if (!p)
	{
		throw Failure::Error::T (message_prefix + "No valid addresses\n");
	}

	if (listen (file_descriptor, SOMAXCONN) == -1)
	{
		std::string message =
		    message_prefix + "listen: " + strerror (errno) + "\n";
		close (file_descriptor);
		throw Failure::Error::T (message);
	}

	return file_descriptor;
}
