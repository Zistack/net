struct T
{
	T ();

	void
	store (const Throwable::T & e);

	void
	poll ();

	void
	clear ();

	~T ();

	std::atomic<Throwable::T *> exception;
};
