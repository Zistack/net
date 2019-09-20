template <bool use_external_store, typename Cancellable>
struct T : private ExceptionStore::T <use_external_store>
{
	T ();

	T (Failure::ExceptionStore::T & exception_store);

	template <typename Function, typename ... Arguments>
	void
	add
	(
		Cancellable cancellable,
		Function && function,
		Arguments && ... arguments
	);

	void
	cancel ();

	~T ();

private:

	template <typename Function, typename ... Arguments>
	static void
	wrapperFunction
	(
		T * collection,
		Function && function,
		Arguments && ... arguments
	);

	std::mutex m_mutex;
	std::condition_variable m_condition_variable;
	bool m_cancelled;
	std::unordered_map <std::thread::id, Thread::T <Cancellable>> m_threads;
};

