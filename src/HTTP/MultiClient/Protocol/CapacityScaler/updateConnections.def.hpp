template <typename Interface>
void
T <Interface>::updateConnections ()
{
	double total_load = 0;
	size_t active_connections = this -> m_active_connections . load ();

	size_t connection_index;
	for
	(
		connection_index = 0;
		connection_index < active_connections;
		++ connection_index
	)
	{
		total_load += this -> interface () . updateLoad (connection_index);
	}

	if (total_load / active_connections < this -> m_min_load)
	{
		size_t new_active_connections = std::min
		(
			std::ceil (total_load / this -> m_min_load),
			1
		);

		for
		(
			;
			active_connections > new_active_connections;
			-- active_connections
		)
		{
			this -> interface () . setInactive (active_connections - 1);
		}
	}
	else if (total_load / active_connections > this -> m_max_load)
	{
		size_t new_active_connections = std::max
		(
			std::ceil (total_load / this -> m_max_load),
			this -> interface () . max_connections
		);

		for
		(
			;
			active_connections < new_active_connections;
			++ active_connections
		)
		{
			this -> interface () . setActive (active_connections);
		}
	}

	this -> m_active_connections . store (active_connections);
}
