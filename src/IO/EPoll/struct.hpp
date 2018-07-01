struct T
{
	T ();

	void
	add (Interface::Watchable::T * watchable);

	Interface::Watchable::T *
	wait ();

	~T ();

	int file_descriptor;
};
