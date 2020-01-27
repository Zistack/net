struct T
{
	T ();

	void
	punchOn ();

	void
	punchOff ();

	double
	updateLoad ();

	double
	load () const;

	~T () = default;

private:

	std::mutex m_mutex;

	bool m_on;
	std::chrono::time_point <std::chrono::steady_clock> m_last_reset;
	std::chrono::time_point <std::chrono::steady_clock> m_last_punch_on;
	std::chrono::steady_clock::duration m_time_on_since_last_reset;

	std::atomic <double> m_load;
};
