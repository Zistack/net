struct T
{
	T (Duration::T timeout, std::function<void(void)> callback);

	void
	cancel ();

	~T ();

	static void
	run (Duration::T timeout,
	    std::mutex * mutex,
	    bool * cancelled,
	    std::function<void(void)> callback);

	std::mutex * mutex;
	bool * cancelled;
};
