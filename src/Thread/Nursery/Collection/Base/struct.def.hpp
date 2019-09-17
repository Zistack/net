template <typename Cancellable>
struct T
{
	T ();

	template <typename Function, typename ... Arguments>
	void
	add
	(
		Cancellable cancellable,
		Function && function,
		Arguments && ... arguments
	);

	~T ();

private:

	void
	cancel ();

	template <typename Function, typename ... Arguments>
	void
	wrapperFunction
	(
		T * collection,
		Function && function,
		Arguments && ... arguments
	);

	Failure::ExceptionStore::T m_exception_store;

	std::mutex m_mutex;
	std::condition_variable m_condition_variable;
	bool m_cancelled;
	std::unordered_map <std::thread::id, Thread::T <Cancellable>> m_threads;
};

