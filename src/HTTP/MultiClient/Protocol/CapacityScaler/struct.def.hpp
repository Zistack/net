template <typename Interface>
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

	size_t
	activeConnections () const;

protected:

	T
	(
		double min_load,
		double max_load,
		std::chrono::steady_clock::duration load_update_interval
	);

	const T &
	capacityScaler () const;

	T &
	capacityScaler ();

	~T () = default;

private:

	void
	updateConnections ();

	// Access to external members

	const Interface &
	interface () const;

	Interface &
	interface ();

	// Given members

	double m_min_load;
	double m_max_load;
	std::chrono::steady_clock::duration m_load_update_interval;

	// Internal members

	std::mutex m_active_mutex;
	std::condition_variable m_active_condition_variable;
	std::atomic <size_t> m_active_connections;
};
