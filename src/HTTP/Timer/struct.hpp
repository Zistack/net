struct T
{
	T (std::function <void (void)> callback);
	~T ();

	static void
	run
	(
		Duration::T timeout,
		std::mutex * mutex,
		bool * cancelled,
		std::boolstd::function <void (void)> callback
	);

	void cancel ();

	std::mutex * mutex;
	bool * cancelled;
};
