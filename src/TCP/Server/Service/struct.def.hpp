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

	ServerProtocol m_server_protocol;
	Config::T m_config;

	// Internal members

	ShutdownSignal::T m_shutdown_signal;
	Failure::ExceptionStore::T m_exception_store;

	// Transient members

	SuppressingScope::T <ShutdownSignal::T> m_shutdown_scope;

	static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
};

template <typename ServerProtocol>
T (ServerProtocol && server_protocol, const Config::T & config) ->
	T <ServerProtocol>;
