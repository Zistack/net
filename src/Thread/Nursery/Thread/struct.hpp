struct T
{
	template <class Function,
	    class Cancel,
	    typename = typename std::enable_if<!std::is_same<std::nullptr_t,
	        typename std::decay<Function>::type>::value>::type>
	T (Function && function, Cancel && cancel)
	noexcept;

	template <class Cancel>
	T (std::nullptr_t, Cancel && cancel)
	noexcept;

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
	Function::T<void(void)> c;

	std::thread thread;
};
