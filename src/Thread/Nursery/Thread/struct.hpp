struct T
{
	template <class Function,
	    typename = typename std::enable_if<!std::is_same<std::nullptr_t,
	        typename std::decay<Function>::type>::value>::type>
	T (Function && function, Failure::Cancellable::T * cancellable)
	noexcept;

	T (std::nullptr_t, Failure::Cancellable::T * cancellable) noexcept;

	T (const T & other) = delete;

	T (T && other) = default;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = default;

	std::thread::id
	id () const noexcept;

	void
	cancel () noexcept;

	void
	reset () noexcept;

	~T ();

	private:
	Failure::Cancellable::T * cancellable;

	std::thread thread;
};
