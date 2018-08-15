struct T
{
	T (IO::Interface::ProtocolFactory::T * protocol_factory,
	    std::string * host,
	    std::string port,
	    IO::Interface::OutputStream::T * log);

	void
	run ();

	void
	stop ();

	void
	kill ();

	~T ();

	void
	serve (IO::Socket::T socket);

	IO::Interface::ProtocolFactory::T * protocol_factory;

	IO::Signal::T * signal;
	IO::ServerSocket::T * server_socket;

	IO::Interface::OutputStream::T * log;
};
