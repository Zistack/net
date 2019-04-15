template <typename ServerProtocol>
struct T
{
	T (ServerProtocol server_protocol, const Config::T & config);

	void
	prime ();

	void
	run ();

	void
	cancel ();

	~T () = default;

private:

	void
	listen (Thread::Nursery::T & nursery);

	void
	accept (Socket::T & server_socket, Thread::Nursery::T & nursery);

	// Given members

	ServerProtocol server_protocol;
	Config::T config;

	// Internal members

	ShutdownSignal::T shutdown_signal;
	Failure::ExceptionStore::T exception_store;

	// Transient members

	SuppressingScope::T <ShutdownSignal::T> shutdown_scope;

	static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
};

template <typename ServerProtocol>
T (ServerProtocol && server_protocol, const Config::T & config) ->
	T <ServerProtocol>;
