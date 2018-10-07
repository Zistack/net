struct T
{
	T (IO::Interface::ProtocolFactory::T * protocol_factory,
	    std::function<IO::Interface::ServerSocket::T *(void)> newSocket);

	void
	run ();

	void
	stop ();

	~T () = default;

	IO::Interface::ProtocolFactory::T * protocol_factory;
	std::function<IO::Interface::ServerSocket::T *(void)> newSocket;

	Shutdown::Signal::T shutdown_signal;
};
