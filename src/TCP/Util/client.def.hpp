int
client (const char * hostname, const char * port)
{
	const std::string message_prefix = "Failed to create TCP client:\n";

	struct addrinfo hints;

	memset (& hints, 0, sizeof (hints));

	hints . ai_family = AF_UNSPEC;
	hints . ai_socktype = SOCK_STREAM;

	struct addrinfo * results;

	int err = getaddrinfo (hostname, port, & hints, & results);

	if (err)
	{
		throw Failure::ResourceError::T
		(
			message_prefix + "getaddrinfo: " + gai_strerror (err) + "\n"
		);
	}

	int client_socket;

	struct addrinfo * p;
	for (p = results; p != nullptr; p = p -> ai_next)
	{
		client_socket = socket
		(
			p -> ai_family,
			p -> ai_socktype,
			p -> ai_protocol
		);

		if (client_socket == -1)
		{
			// We might want to report this someday.
			continue;
		}

		if (connect (client_socket, p -> ai_addr, p -> ai_addrlen) == -1)
		{
			close (client_socket);
			// We might want to report this someday.
			continue;
		}

		break;
	}

	freeaddrinfo (results);

	if (! p)
	{
		throw Failure::ResourceError::T
		(
			message_prefix + "No valid addresses\n"
		);
	}

	if
	(
		fcntl
		(
			client_socket,
			F_SETFD,
			fcntl (client_socket, F_GETFD, 0) | O_NONBLOCK
		) == -1
	)
	{
		std::string message =
			message_prefix + "fcntl: " + Failure::Util::strerror (errno) + "\n";
		close (client_socket);
		throw Failure::ResourceError::T (message);
	}

	return client_socket;
}
