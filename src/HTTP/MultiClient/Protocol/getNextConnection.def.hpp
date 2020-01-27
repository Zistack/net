template <template <typename> typename ClientService>
size_t
T <ClientService>::getNextConnection ()
{
	size_t active_connections =
		this -> capacityScaler () . activeConnections ();

	size_t next_connection = this -> m_next_connection . load ();

	while
	(
		active_connections &&
			! this -> m_next_connection . compare_exchange_weak
			(
				& next_connection,
				(next_connection + 1) %
					(
						active_connections =
							this -> capacityScaler () . activeConnections ()
					)
			)
	);

	if (active_connections) return next_connection;
	else throw Failure::ServiceError::T ("Protocol is not running\n");
}
