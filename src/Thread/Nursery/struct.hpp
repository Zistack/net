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

	template <typename Cancellable,
	    typename Function,
	    typename... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	add (Cancellable & cancellable,
	    Function && function,
	    Arguments &&... arguments) noexcept;

	template <typename Function,
	    typename... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	add (Function && function, Arguments &&... arguments) noexcept;

	template <typename Cancellable,
	    typename Function,
	    typename... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	add (Cancellable * cancellable,
	    Function && function,
	    Arguments &&... arguments) noexcept;

	template <typename Cancellable,
	    typename Function,
	    typename... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	run (Cancellable & cancellable,
	    Function && function,
	    Arguments &&... arguments) noexcept;

	template <typename Function,
	    typename... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	run (Function && function, Arguments &&... arguments) noexcept;

	template <typename Cancellable,
	    typename Function,
	    typename... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	run (Cancellable * cancellable,
	    Function && function,
	    Arguments &&... arguments) noexcept;

	template <typename Cancellable,
	    typename Function,
	    typename... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	call (Cancellable & cancellable,
	    Function && function,
	    Arguments &&... arguments);

	template <typename Function,
	    typename... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	call (Function && function, Arguments &&... arguments);

	template <typename Cancellable,
	    typename Function,
	    typename... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<Function, Arguments...>::value>::type>
	void
	call (Cancellable * cancellable,
	    Function && function,
	    Arguments &&... arguments);

	void
	cancel () noexcept;

	~T () noexcept (false);

	private:
	template <typename Cancellable, typename Function, typename... Arguments>
	bool
	start (Cancellable * cancellable,
	    Function && function,
	    Arguments &&... arguments) noexcept;

	template <typename Function, typename... Arguments>
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

	static_assert (Failure::TypeTraits::IsCancellable::T<T>::value);
};
