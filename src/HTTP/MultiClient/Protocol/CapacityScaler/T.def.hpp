template <typename Interface>
T <Interface>::T
(
	double min_load,
	double max_load,
	std::chrono::steady_clock::duration load_update_interval
)
:	m_min_load (min_load),
	m_max_load (max_load),
	m_load_update_interval (load_update_interval)
{
}
