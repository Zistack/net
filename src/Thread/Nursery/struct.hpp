struct T
{
	T (Failure::ExceptionStore::T * exception_store = nullptr);
	T (const T & other) = delete;

	void
	add (std::function<void(void)> run);

	void
	add (std::function<void(void)> run, std::function<void(void)> cancel);

	void
	add (std::function<void(void)> run,
	    std::function<void(void)> clean,
	    std::function<void(void)> cancel);

	void
	cancel ();

	~T ();

	private:
	void
	start (std::function<void(void)> run, std::function<void(void)> cancel);

	void
	finish ();

	std::mutex m;
	std::condition_variable c;

	std::unordered_map<std::thread::id,
	    std::pair<std::thread *, std::function<void(void)>>>
	    threads;

	Failure::ExceptionStore::T exception_store;
	Failure::ExceptionStore::T * external_store;
};
