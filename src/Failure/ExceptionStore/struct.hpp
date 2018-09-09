struct T
{
	T ();

	void
	store (const std::exception & e);

	void
	store (std::exception_ptr e);

	void
	poll ();

	void
	clear ();

	~T () = default;

	std::mutex m;
	std::exception_ptr exception;
};
