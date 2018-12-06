struct T : IO::Interface::Watchable::T, Failure::Cancellable::T
{
	T ();

	int
	fileDescriptor () const override;

	IO::Interface::Watchable::Events::T
	events () const override;

	void
	cancel () override;

	bool
	running ();

	~T () = default;

	private:
	void
	open ();

	void
	close ();

	IO::Signal::T signal;
	std::atomic<State::T> state;

	friend Scope::T<T>;
	friend SuppressingScope::T<T>;
};
