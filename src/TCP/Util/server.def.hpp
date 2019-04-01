int
server (const char * hostname, const char * port)
{
	std::string message_prefix = "Failed to create TCP server:\n";

	struct addrinfo hints;

	memset (&hints, 0, sizeof (hints));

	hints . ai_flags = AI_PASSIVE;
	hints . ai_family = AF_INET6;
	hints . ai_socktype = SOCK_STREAM;
	hints . ai_protocol = IPPROTO_TCP;

	struct addrinfo * results;

	int err = getaddrinfo (hostname, port, & hints, & results);

	if (err)
	{
		throw Failure::ResourceError::T
		(
			message_prefix + "getaddrinfo: " + gai_strerror (err) + "\n"
		);
	}

	int server_socket;

	struct addrinfo * p;
	for (p = results; p != nullptr; p = p -> ai_next)
	{
		server_socket = socket
		(
			p -> ai_family,
			p -> ai_socktype | SOCK_NONBLOCK,
			p -> ai_protocol
		);

		if (server_socket == -1)
		{
			// We might want to report this someday.
			continue;
		}

		int yes = 1;
		if
		(
			setsockopt
			(
				server_socket,
				SOL_SOCKET,
				SO_REUSEADDR,
				& yes,
				sizeof (yes)
			) == -1
		)
		{
			std::string message =
				message_prefix + "setsockopt: " + strerror (errno) + "\n";
			freeaddrinfo (results);
			close (server_socket);
			throw Failure::ResourceError::T (message);
		}

		if (bind (server_socket, p -> ai_addr, p -> ai_addrlen) == -1)
		{
			close (server_socket);
			// We might want to report this someday.
			continue;
		}

		break;
	}

	freeaddrinfo (results);

	if (!p)
	{
		throw Failure::ResourceError::T
		(
			message_prefix + "No valid addresses\n"
		);
	}

	if (listen (server_socket, SOMAXCONN) == -1)
	{
		std::string message =
			message_prefix + "listen: " + strerror (errno) + "\n";
		close (server_socket);
		throw Failure::ResourceError::T (message);
	}

	return server_socket;
}
