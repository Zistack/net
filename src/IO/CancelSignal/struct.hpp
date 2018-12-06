struct T : Interface::Watchable::T, Failure::Cancellable::T
{
	T ();

	Interface::Watchable::Events::T
	events () const override;

	int
	fileDescriptor () const override;

	void
	cancel () override;

	void
	clear ();

	~T () = default;

	private:
	std::atomic<bool> cancelled;
	Signal::T signal;
};
