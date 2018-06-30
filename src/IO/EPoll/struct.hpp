struct T
{
	T ();

	void
	add (Interface::Watchable::T * watchable);

	Watchable::T *
	wait ();

	~T ();

	int fd;
};
