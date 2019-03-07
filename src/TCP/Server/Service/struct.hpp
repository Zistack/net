template <typename Protocol>
struct T : Failure::Cancellable::T
{
	T (Protocol server_protocol, const Config::T & config);

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

	Protocol server_protocol;
	Config::T config;

	// Internal members

	Shutdown::Signal::T shutdown_signal;
	Failure::ExceptionStore::T exception_store;

	// Transient members

	SuppressingScope::T<Shutdown::Signal::T> shutdown_scope;
};

template <typename Protocol>
T (Protocol && protocol, const Config::T & config)->T<Protocol>;
