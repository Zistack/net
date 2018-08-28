struct T
{
	T (Failure::ExceptionStore::T & exception_store);

	template <class Function, class... Args>
	void
	add (Function && function, Args &&... args);

	template <class Function, class... Args>
	void
	run (Function && function, Args &&... args);

	void
	join ();

	~T ();

	std::mutex mutex;
	std::condition_variable condition_variable;

	std::unordered_map<std::thread::id, std::thread *> threads;

	Failure::ExceptionStore::T & exception_store;
};
