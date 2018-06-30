struct T : IO::Server::T
{
	T (IO::Interface::ProtocolFactory::T * protocol_factory,
		std::string * host,
		std::string port,
		IO::OutputStream::T * log);

	void
	run ();

	void
	stop ();

	void
	kill ();

	~T ();

	IO::Interface::ProtocolFactory::T * protocol_factory;

	IO::Signal::T * signal;
	IO::ServerSocket::T * server_socket;

	IO::OutputStream::T * log;
};
