T::T (const char * hostname, const char * port)
{
	const std::string message_prefix = "TCP::Client::T::T\n";

	struct addrinfo hints;

	memset (&hints, 0, sizeof (hints));

	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	struct addrinfo * results;

	int err = getaddrinfo (hostname, port, &hints, &results);

	if (err)
	{
		throw Failure::Error::T (
		    message_prefix + "getaddrinfo: " + gai_strerror (err) + "\n");
	}

	struct addrinfo * p;

	for (p = results; p != nullptr; p = p->ai_next)
	{
		this->file_descriptor =
		    socket (p->ai_family, p->ai_socktype, p->ai_protocol);

		if (this->file_descriptor == -1)
		{
			// We might want to report this someday.
			continue;
		}

		if (connect (this->file_descriptor, p->ai_addr, p->ai_addrlen) == -1)
		{
			close (this->file_descriptor);
			// We might want to report this someday.
			continue;
		}

		break;
	}

	freeaddrinfo (results);

	if (!p) throw Failure::Error::T (message_prefix + "No valid addresses\n");

	if (fcntl (this->file_descriptor,
	        F_SETFD,
	        fcntl (this->file_descriptor, F_GETFD, 0) | O_NONBLOCK) == -1)
	{
		std::string message =
		    message_prefix + "fcntl: " + strerror (errno) + "\n";
		close (this->file_descriptor);
		throw Failure::Error::T (message);
	}

	this->input_stream =
	    new IO::FileDescriptor::InputStream::T (this->file_descriptor);
	this->output_stream =
	    new IO::FileDescriptor::OutputStream::T (this->file_descriptor);
}

T::T (const Config::T & config) :
    T (config.hostnameCString (), config.portCString ())
{
}

T::T (JSON::Value::T * config_value) : T (Config::T (config_value)) {}

T::T (Server::T * server)
{
	const std::string message_prefix = "TCP::Client::T::T\n";

	while (
	    (this->file_descriptor = accept4 (
	         server->file_descriptor, nullptr, nullptr, SOCK_NONBLOCK)) == -1)
	{
		switch (errno)
		{
		case EAGAIN:
#if EWOULDBLOCK != EAGAIN
		case EWOULDBLOCK:
#endif
		case EINTR:
			continue;
		case ECONNABORTED:
			throw AbortedException::T ();
		default:
			throw Failure::Error::T (
			    message_prefix + "accept: " + strerror (errno) + "\n");
		}
	}

	this->input_stream =
	    new IO::FileDescriptor::InputStream::T (this->file_descriptor);
	this->output_stream =
	    new IO::FileDescriptor::OutputStream::T (this->file_descriptor);
}
