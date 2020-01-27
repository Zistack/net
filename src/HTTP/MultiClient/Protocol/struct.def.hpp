template <template <typename> typename ClientService>
struct T : private Interface::T <ClientService>
{
	template
	<
		typename ... ConnectionArguments,
		typename = std::enable_if_t
		<
			std::is_constructible_v
			<
				Connection::T <ClientService>,
				ConnectionArguments ...
			>
		>
	>
	T
	(
		size_t max_connections,
		double min_load,
		double max_load,
		std::chrono::steady_clock::duration load_update_interval,
		ConnectionArguments && ... connection_arguments
	);

	void
	prime ();

	void
	run ();

	void
	stop ();

	void
	cancel ();

	Response::T
	makeRequest (Request::T && request);

	~T () = default;

private:

	size_t
	getNextConnection ();

	std::atomic <size_t> m_next_connection;
};
