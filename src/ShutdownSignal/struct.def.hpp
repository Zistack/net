struct T
{
	T ();

	int
	fileDescriptor () const;

	IO::Watchable::Events::T
	events () const;

	void
	cancel ();

	bool
	running ();

	~T () = default;

private:

	void
	open ();

	void
	close ();

	IO::Signal::T m_signal;
	std::atomic <State::T> m_state;

	friend Scope::T <T>;
	friend SuppressingScope::T <T>;
};

static_assert (IO::TypeTraits::IsWatchable::T <T>::value);
static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
