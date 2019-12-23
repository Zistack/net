struct T
{
	T ();

	T (T && other);

	T &
	operator = (T && other);

	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	void
	cancel ();

	void
	clear ();

	~T () = default;

private:

	std::atomic <bool> m_cancelled;
	Signal::T m_signal;
};

static_assert (IsWatchable::T <T>::value);
static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
static_assert (IsClearable::T <T>::value);
