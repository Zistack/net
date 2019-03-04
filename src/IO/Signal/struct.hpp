struct T : Interface::Watchable::T
{
	T ();

	T (const T & other) = delete;

	T (T && other);

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = delete;

	void
	send ();

	bool
	recieve ();

	Interface::Watchable::Events::T
	events () const override;

	int
	fileDescriptor () const override;

	~T ();

	int file_descriptor;
};
