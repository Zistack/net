template <template <typename> typename ClientService>
struct T
:	ConnectionManager::T <ClientService>, CapacityScaler::T <T <ClientService>>
{
	using ConnectionManager::T <ClientService>::updateLoad;
	using ConnectionManager::T <ClientService>::setActive;
	using ConnectionManager::T <ClientService>::setInactive;
	using ConnectionManager::T <ClientService>::maxConnections;

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
	T
	(
		size_t max_connections,
		double min_load,
		double max_load,
		std::chrono::steady_clock::duration load_update_interval,
		ConnectionArguments && ... connection_arguments
	);

	~T () = default;
};
