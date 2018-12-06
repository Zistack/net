struct T : Failure::Cancellable::T
{
	T () noexcept;

	T (Failure::ExceptionStore::T & exception_store) noexcept;

	T (const T & other) = delete;

	T (T && other) = delete;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = delete;

	template <class Function>
	void
	add (Function && function,
	    Failure::Cancellable::T * cancellable = nullptr) noexcept;

	template <class Function>
	void
	run (Function && function,
	    Failure::Cancellable::T * cancellable = nullptr) noexcept;

	template <class Function>
	void
	call (Function && function,
	    Failure::Cancellable::T * cancellable = nullptr);

	void
	cancel () noexcept override;

	~T () noexcept (false);

	private:
	template <class Function>
	bool
	start (Function && function,
	    Failure::Cancellable::T * cancellable) noexcept;

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
