struct T
{
	T (IO::Interface::ProtocolFactory::T & protocol_factory,
	    const char * hostname,
	    const char * port,
	    IO::Interface::OutputStream::T * log);

	void
	run ();

	void
	close ();

	void
	stop ();

	void
	kill ();

	~T ();

	static void
	serve (T * server, IO::Socket::T * socket);

	IO::Interface::ProtocolFactory::T & protocol_factory;

	IO::Signal::T * signal;
	IO::ServerSocket::T * server_socket;

	Thread::ConcurrentBag::T<Connection::T *> connections;

	IO::Interface::OutputStream::T * log;
};
