struct T
{
	T ();

	bool
	store (const std::exception & e);

	bool
	store (std::exception_ptr e);

	template <class Callable>
	bool
	tryStore (Callable && f);

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
