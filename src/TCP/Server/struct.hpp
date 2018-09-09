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

	IO::Interface::ProtocolFactory::T & protocol_factory;

	IO::Signal::T * shutdown_signal;
	IO::ServerSocket::T * server_socket;

	IO::Interface::OutputStream::T * log;
};
