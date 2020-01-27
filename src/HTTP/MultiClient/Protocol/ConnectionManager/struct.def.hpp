template <template <typename> typename ClientService>
struct T
{
	void
	prime ();

	void
	run ();

	void
	stop ();

	void
	cancel ();

	Response::T
	makeRequest (size_t connection_index, Request::T && request);

protected:

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
	T (size_t max_connections, ConnectionArguments && ... connection_arguments);

	const T &
	connectionManager () const;

	T &
	connectionManager ();

	size_t
	maxConnections () const;

	double
	updateLoad (size_t connection_index);

	void
	setActive (size_t connection_index);

	void
	setInactive (size_t connection_index);

	~T () = default;

private:

	// Internal members.

	std::vector <Connection::T <ClientService>> m_connections;
};
