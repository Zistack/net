int
T::newSocket (const Config::T & config)
{
	const std::string message_prefix = "TCP::Client::Socket::T::newSocket\n";

	struct addrinfo hints;

	memset (&hints, 0, sizeof (hints));

	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

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
		file_descriptor = socket (p->ai_family, p->ai_socktype, p->ai_protocol);

		if (file_descriptor == -1)
		{
			// We might want to report this someday.
			continue;
		}

		if (connect (file_descriptor, p->ai_addr, p->ai_addrlen) == -1)
		{
			close (file_descriptor);
			// We might want to report this someday.
			continue;
		}

		break;
	}

	freeaddrinfo (results);

	if (!p) throw Failure::Error::T (message_prefix + "No valid addresses\n");

	if (fcntl (file_descriptor,
	        F_SETFD,
	        fcntl (file_descriptor, F_GETFD, 0) | O_NONBLOCK) == -1)
	{
		std::string message =
		    message_prefix + "fcntl: " + strerror (errno) + "\n";
		close (file_descriptor);
		throw Failure::Error::T (message);
	}

	return file_descriptor;
}
