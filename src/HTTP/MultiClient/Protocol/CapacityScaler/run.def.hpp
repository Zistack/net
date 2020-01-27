template <typename Interface>
void
T <Interface>::run ()
{
	std::unique_lock active_lock (this -> m_active_mutex);

	std::chrono::time_point now = std::chrono::steady_clock::now ();

	while (this -> m_active_connections . load ())
	{
		this -> updateConnections ();

		std::chrono::time_point next_update = now + this -> m_load_update_interval;

		this -> m_active_condition_variable . wait_until
		(
			active_lock,
			next_update,
			[&] ()
			{
				return (std::chrono::steady_clock::now () >= next_update) ||
					! this -> m_active_connections;
			}
		);

		now = next_update;
	}
}
