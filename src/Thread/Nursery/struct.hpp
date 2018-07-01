struct T
{
	T (Failure::ExceptionStore::T & exception_store);

	template <typename Function, typename... Args>
	void
	add (Function function, Args... args);

	template <typename Function, typename... Args>
	void
	run (Function function, Args... args);

	void
	join ();

	~T ();

	std::mutex mutex;
	std::condition_variable condition_variable;

	std::unordered_map<std::thread::id, std::thread *> threads;

	Failure::ExceptionStore::T & exception_store;
};
