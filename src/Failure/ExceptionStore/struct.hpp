struct T
{
	T ();

	bool
	store (const std::exception & e);

	bool
	store (std::exception_ptr e);

	void
	poll ();

	void
	clear ();

	~T () = default;

	std::mutex m;
	std::exception_ptr exception;
};
