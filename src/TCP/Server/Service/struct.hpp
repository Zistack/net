struct T : Failure::Cancellable::T
{
	T (IO::Interface::Server::Protocol::T & server_protocol,
	    const Config::T & config);

	void
	prime ();

	void
	run ();

	void
	cancel () override;

	~T () = default;

	private:
	void
	listen (Thread::Nursery::T & nursery);

	void
	accept (Socket::T & server_socket, Thread::Nursery::T & nursery);

	// Given members

	IO::Interface::Server::Protocol::T & server_protocol;
	Config::T config;

	// Internal members

	Shutdown::Signal::T shutdown_signal;
	Failure::ExceptionStore::T exception_store;

	// Transient members

	SuppressingScope::T<Shutdown::Signal::T> shutdown_signal_scope;
};
