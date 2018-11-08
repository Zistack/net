struct T
{
	T () noexcept;

	T (Failure::ExceptionStore::T & exception_store) noexcept;

	T (const T & other) = delete;

	T (T && other) = delete;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = delete;

	template <class Function, class Cancel = std::nullptr_t>
	void
	add (Function && function, Cancel && cancel = nullptr) noexcept;

	template <class Function, class Cancel = std::nullptr_t>
	void
	run (Function && function, Cancel && cancel = nullptr) noexcept;

	template <class Function, class Cancel = std::nullptr_t>
	void
	call (Function && function, Cancel && cancel = nullptr);

	void
	cancel () noexcept;

	~T () noexcept (false);

	private:
	template <class Function, class Cancel>
	bool
	start (Function && function, Cancel && cancel);

	void
	finish () noexcept;

	void
	join ();

	std::mutex m;
	std::condition_variable c;

	std::unordered_map<std::thread::id, Thread::T> threads;

	std::unique_ptr<Failure::ExceptionStore::T> internal_store;
	Failure::ExceptionStore::T & exception_store;
};
