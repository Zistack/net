int
client
(
	const std::optional <URI::Authority::Host::T> & hostname,
	uint64_t port
)
{
	const std::string message_prefix = "Failed to create TCP client:\n";

	struct addrinfo hints;

	memset (& hints, 0, sizeof (hints));

	hints . ai_flags = AI_NUMERICSERV;
	hints . ai_family = AF_UNSPEC;
	hints . ai_socktype = SOCK_STREAM;

	struct addrinfo * results;

	int err = getaddrinfo
	(
		hostname ?
			URI::Authority::Host::toString (* hostname) . data () :
			nullptr,
		std::to_string (port) . data (),
		& hints,
		& results
	);

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

	try
	{
		IO::Util::setNonblocking (client_socket);
	}
	catch (Failure::ResourceError::T & e)
	{
		close (client_socket);
		throw Failure::ResourceError::T (message_prefix + e . what ());
	}

	return client_socket;
}
