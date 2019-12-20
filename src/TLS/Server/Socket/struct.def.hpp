struct T
{
	T ();

	T
	(
		const std::optional <URI::Authority::Host::T> & hostname,
		const std::optional <uint64_t> & port
	);

	T (const T & other) = delete;

	T (T && other);

	T &
	operator = (const T & other) = delete;

	T &
	operator = (T && other);

	int
	accept ();

	IO::Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	~T ();

private:

	void
	clean ();

	int m_tcp_socket;
};

static_assert (IO::TypeTraits::IsWatchable::T <T>::value);
