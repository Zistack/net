struct T : Failure::Cancellable::T
{
	T (IO::Interface::Server::Protocol::T & server_protocol);

	void
	prime ();

	void
	run ();

	void
	cancel () override;

	virtual ~T () = default;

	protected:
	virtual std::unique_ptr<IO::Interface::Server::Socket::T>
	newServerSocket () = 0;

	private:
	void
	listen (Thread::Nursery::T & nursery);

	// Given members

	IO::Interface::Server::Protocol::T & server_protocol;

	// Internal members

	Shutdown::Signal::T shutdown_signal;
	Failure::ExceptionStore::T exception_store;

	// Transient members

	std::unique_ptr<IO::Interface::Server::Socket::T> server_socket;
	SuppressingScope::T<Shutdown::Signal::T> shutdown_signal_scope;
};
