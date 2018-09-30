struct T : IO::Interface::Watchable::T
{
	T ();

	int
	fileDescriptor () const override;

	IO::Interface::Watchable::Events::T
	events () const override;

	void
	set ();

	void
	reset ();

	void
	clear ();

	~T () = default;

	IO::Signal::T signal;
	std::atomic<State::T> state;
};
