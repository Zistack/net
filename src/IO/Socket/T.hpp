T::T (std::string hostname, std::string port, OutputStream::T * log)
{
	const std::string message_prefix = "IO::Socket::T\n";

	try
	{
		struct addrinfo hints;

		memset (& hints, 0, sizeof (hints));

		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM | SOCK_NONBLOCK;

		struct addrinfo * results;

		int err = getaddrinfo (hostname.data (), port.data (), & hints, & results);

		if (err)
		{
			throw ResourceError::T (
				"getaddrinfo: " + gai_strerror (err) + "\n"
			);
		}

		struct addrinfo * p;

		for (p = results; p != NULL; p = p -> ai_next)
		{
			this -> fd = socket (p -> ai_family, p -> ai_socktype, p -> ai_protocol);

			if (this -> fd == -1)
			{
				if (log) log.print ("socket: " + strerror (errno) + "\n");
				continue;
			}

			int yes = 1;
			if (setsockopt (this -> fd, SOL_SOCKET, SO_LINGER, &yes, sizeof (yes)) == -1)
			{
				close (this -> fd);
				throw ResourceError::T (
					"setsockopt: " + strerror (errno) + "\n"
				);
			}

			if (connect (this -> fd, p -> ai_addr, p -> ai_addrlen) == -1)
			{
				close (this -> fd);
				if (log) log.print ("connect: " + strerror (errno) + "\n");
				continue;
			}

			break;
		}

		freeaddrinfo (result);

		if (! p) throw ResourceError::T ("No valid addresses\n");

		this -> input_stream = new FileDescriptor::InputStream::T (this -> fd);
		this -> output_stream = new FileDescriptor::OutputStream::T (this -> fd);
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}

T::T (int fd) :
	input_stream (new FileDescriptor::InputStream::T (fd)),
	output_stream (new FileDescriptor::OutputStream::T (fd)),
	fd (fd)
{
}
