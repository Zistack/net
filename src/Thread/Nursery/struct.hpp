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

	template <class Function,
	    class... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	add (Failure::Cancellable::T & cancellable,
	    Function && function,
	    Arguments &&... arguments) noexcept;

	template <class Function,
	    class... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	add (Function && function, Arguments &&... arguments) noexcept;

	template <class Function,
	    class... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	add (Failure::Cancellable::T * cancellable,
	    Function && function,
	    Arguments &&... arguments) noexcept;

	template <class Function,
	    class... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	run (Failure::Cancellable::T & cancellable,
	    Function && function,
	    Arguments &&... arguments) noexcept;

	template <class Function,
	    class... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	run (Function && function, Arguments &&... arguments) noexcept;

	template <class Function,
	    class... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	run (Failure::Cancellable::T * cancellable,
	    Function && function,
	    Arguments &&... arguments) noexcept;

	template <class Function,
	    class... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	call (Failure::Cancellable::T & cancellable,
	    Function && function,
	    Arguments &&... arguments);

	template <class Function,
	    class... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	call (Function && function, Arguments &&... arguments);

	template <class Function,
	    class... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	call (Failure::Cancellable::T * cancellable,
	    Function && function,
	    Arguments &&... arguments);

	void
	cancel () noexcept override;

	~T () noexcept (false);

	private:
	template <class Function, class... Arguments>
	bool
	start (Failure::Cancellable::T * cancellable,
	    Function && function,
	    Arguments &&... arguments) noexcept;

	template <class Function, class... Arguments>
	void
	execute (Function && function, Arguments &&... arguments) noexcept;

	void
	finish () noexcept;

	void
	join ();

	std::mutex m;
	std::condition_variable c;
	bool cancelled;

	std::unordered_map<std::thread::id, Thread::T> threads;

	std::unique_ptr<Failure::ExceptionStore::T> internal_store;
	Failure::ExceptionStore::T & exception_store;
};
