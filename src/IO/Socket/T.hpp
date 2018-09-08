T::T (const char * hostname,
    const char * port,
    Interface::OutputStream::T * log)
{
	const std::string message_prefix = "IO::Socket::T::T\n";

	try
	{
		struct addrinfo hints;

		memset (&hints, 0, sizeof (hints));

		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;

		struct addrinfo * results;

		int err = getaddrinfo (hostname, port, &hints, &results);

		if (err)
		{
			throw Failure::ResourceError::T (
			    std::string ("getaddrinfo: ") + gai_strerror (err) + "\n");
		}

		struct addrinfo * p;

		for (p = results; p != nullptr; p = p->ai_next)
		{
			this->file_descriptor =
			    socket (p->ai_family, p->ai_socktype, p->ai_protocol);

			if (this->file_descriptor == -1)
			{
				std::string message =
				    std::string ("socket: ") + strerror (errno) + "\n";
				if (log) log->print (message);
				continue;
			}

			if (connect (this->file_descriptor, p->ai_addr, p->ai_addrlen) ==
			    -1)
			{
				std::string message =
				    std::string ("connect: ") + strerror (errno) + "\n";
				close (this->file_descriptor);
				if (log) log->print (message);
				continue;
			}

			break;
		}

		freeaddrinfo (results);

		if (!p) throw Failure::ResourceError::T ("No valid addresses\n");

		if (fcntl (this->file_descriptor,
		        F_SETFD,
		        fcntl (this->file_descriptor, F_GETFD, 0) | O_NONBLOCK) == -1)
		{
			std::string message =
			    std::string ("fcntl: ") + strerror (errno) + "\n";
			close (this->file_descriptor);
			throw Failure::ResourceError::T (message);
		}

		this->input_stream =
		    new FileDescriptor::InputStream::T (this->file_descriptor);
		this->output_stream =
		    new FileDescriptor::OutputStream::T (this->file_descriptor);
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}

T::T (int file_descriptor) :
    input_stream (new FileDescriptor::InputStream::T (file_descriptor)),
    output_stream (new FileDescriptor::OutputStream::T (file_descriptor)),
    file_descriptor (file_descriptor)
{
}
