template <template <typename> typename ClientService>
template <typename ... ConnectionArguments, typename>
T <ClientService>::T
(
	size_t max_connections,
	double min_load,
	double max_load,
	std::chrono::steady_clock::duration load_update_interval,
	ConnectionArguments && ... connection_arguments
)
:	ConnectionManager::T <ClientService>
	(
		max_connections,
		std::forward <ConnectionArguments> (connection_arguments) ...
	),
	CapacityScaler::T <T <ClientService>>
	(
		min_load,
		max_load,
		load_update_interval
	)
{
}
