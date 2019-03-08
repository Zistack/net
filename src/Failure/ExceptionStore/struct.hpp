struct T
{
	T ();

	bool
	store (const std::exception & e);

	bool
	store (std::exception_ptr e);

	template <typename Function, typename... Arguments>
	bool
	tryStore (Function && function, Arguments &&... arguments);

	operator bool () const;

	void
	poll ();

	void
	pop ();

	void
	clear ();

	~T () = default;

	private:
	std::mutex m;
	std::exception_ptr exception;
};
