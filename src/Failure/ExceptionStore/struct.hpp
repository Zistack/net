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

/*
 * Due to the limitations of C++, any exception thrown from poll must not be
 * allowed to delete the ExceptionStore object by unwinding the stack, no
 * matter how many times it is rethrown.
 */
