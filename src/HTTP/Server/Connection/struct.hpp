struct T : IO::Protocol::T
{
	T (Server::T * server);

	void
	init (IO::Socket::T * socket);

	void
	event ();

	void
	clean ();

	~T ();

	Server::T * server;

	IO::Socket::T * socket;

	std::list <ResponsePromise::T *> response_queue;

	Nursery::T nursery;
};
