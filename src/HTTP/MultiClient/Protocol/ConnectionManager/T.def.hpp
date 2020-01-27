template <template <typename> typename ClientService>
template <typename ... ConnectionArguments, typename>
T <ClientService>::T
(
	size_t max_connections,
	ConnectionArguments && ... connection_arguments
)
{
	this -> m_connections . reserve (max_connections);

	size_t connection_index;
	for
	(
		connection_index = 0;
		connection_index < max_connections;
		++ connection_index
	)
	{
		this -> m_connections . emplace_back
		(
			std::forward <ConnectionArguments> (connection_arguments) ...
		);
	}

	this -> m_connections . shrink_to_fit ();
}
