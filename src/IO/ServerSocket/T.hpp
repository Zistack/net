T::T (std::string * host, std::string port, Interface::OutputStream::T * log)
{
	std::string message_prefix = "IO::ServerSocket::T\n";

	try
	{
		struct addrinfo hints;

		memset (&hints, 0, sizeof (hints));

		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM | SOCK_NONBLOCK;
		hints.ai_flags = AI_PASSIVE;

		struct addrinfo * results;

		const char * node = host ? host->data () : NULL;

		int err = getaddrinfo (node, port.data (), &hints, &results);

		if (err)
		{
			throw ResourceError::T (
			    std::string ("getaddrinfo: ") + gai_strerror (err) + "\n");
		}

		struct addrinfo * p;

		for (p = results; p != NULL; p = p->ai_next)
		{
			this->file_descriptor =
			    socket (p->ai_family, p->ai_socktype, p->ai_protocol);

			if (this->file_descriptor == -1)
			{
				if (log)
					log->print (
					    std::string ("socket: ") + strerror (errno) + "\n");
				continue;
			}

			int yes = 1;
			if (setsockopt (this->file_descriptor,
			        SOL_SOCKET,
			        SO_REUSEADDR,
			        &yes,
			        sizeof (yes)) == -1)
			{
				close (this->file_descriptor);
				throw ResourceError::T (
				    std::string ("setsockopt: ") + strerror (errno) + "\n");
			}

			if (setsockopt (this->file_descriptor,
			        SOL_SOCKET,
			        SO_LINGER,
			        &yes,
			        sizeof (yes)) == -1)
			{
				close (this->file_descriptor);
				throw ResourceError::T (
				    std::string ("setsockopt: ") + strerror (errno) + "\n");
			}

			if (bind (this->file_descriptor, p->ai_addr, p->ai_addrlen) == -1)
			{
				close (this->file_descriptor);
				if (log)
					log->print (
					    std::string ("bind: ") + strerror (errno) + "\n");
				continue;
			}

			break;
		}

		freeaddrinfo (results);

		if (!p)
		{
			throw ResourceError::T ("No valid addresses\n");
		}

		if (listen (this->file_descriptor, SOMAXCONN) == -1)
		{
			close (this->file_descriptor);
			throw ResourceError::T (
			    std::string ("listen: ") + strerror (errno) + "\n");
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
