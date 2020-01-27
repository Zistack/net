template <typename ServerProtocol>
struct T
{
	template
	<
		typename ... ProtocolArguments,
		typename = std::enable_if_t
		<
			std::is_constructible_v <ServerProtocol, ProtocolArguments ...>
		>
	>
	T (const Config::T & config, ProtocolArguments && ... protocol_arguments);

	void
	prime ();

	void
	run ();

	void
	cancel ();

	~T () = default;

private:

	using ConnectionProtocol =
		decltype (* std::declval <ServerProtocol> () . make ());

	void
	accept
	(
		Socket::T & server_socket,
		Thread::Nursery::Collection::T <true, ConnectionProtocol> & nursery
	);

	// Given members

	Config::T m_config;
	ServerProtocol m_server_protocol;

	// Internal members

	ShutdownSignal::T m_shutdown_signal;
	Failure::ExceptionStore::T m_exception_store;

	// Transient members

	SuppressingScope::T <ShutdownSignal::T> m_shutdown_scope;
};

static_assert (Failure::IsCancellable::T <T <IO::DummyServerProtocol::T>>::value);
