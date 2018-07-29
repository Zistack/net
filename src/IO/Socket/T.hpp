T::T (std::string hostname, std::string port, Interface::OutputStream::T * log)
{
	const std::string message_prefix = "IO::Socket::T\n";

	try
	{
		struct addrinfo hints;

		memset (&hints, 0, sizeof (hints));

		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM | SOCK_NONBLOCK;

		struct addrinfo * results;

		int err =
		    getaddrinfo (hostname.data (), port.data (), &hints, &results);

		if (err)
		{
			throw Failure::ResourceError::T (
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
			        SO_LINGER,
			        &yes,
			        sizeof (yes)) == -1)
			{
				close (this->file_descriptor);
				throw Failure::ResourceError::T (
				    std::string ("setsockopt: ") + strerror (errno) + "\n");
			}

			if (connect (this->file_descriptor, p->ai_addr, p->ai_addrlen) ==
			    -1)
			{
				close (this->file_descriptor);
				if (log)
					log->print (
					    std::string ("connect: ") + strerror (errno) + "\n");
				continue;
			}

			break;
		}

		freeaddrinfo (results);

		if (!p) throw Failure::ResourceError::T ("No valid addresses\n");

		this->input_stream =
		    FileDescriptor::InputStream::T (this->file_descriptor);
		this->output_stream =
		    FileDescriptor::OutputStream::T (this->file_descriptor);
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}

T::T (int file_descriptor) :
    input_stream (FileDescriptor::InputStream::T (file_descriptor)),
    output_stream (FileDescriptor::OutputStream::T (file_descriptor)),
    file_descriptor (file_descriptor)
{
}
