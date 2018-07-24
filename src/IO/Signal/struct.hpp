struct T : Interface::Watchable::T
{
	T ();

	void
	send ();

	void
	recieve ();

	Interface::Watchable::Events::T
	events () const override;

	int
	fileDescriptor () const override;

	~T ();

	int file_descriptor;
};
