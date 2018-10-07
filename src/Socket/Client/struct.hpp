struct T
{
	T (IO::Interface::Protocol::T * protocol,
	    std::function<IO::Interface::ClientSocket::T *(void)> newSocket);

	void
	run ();

	void
	stop ();

	~T () = default;

	IO::Interface::Protocol::T * protocol;

	std::function<IO::Interface::ClientSocket::T *(void)> newSocket;
};
