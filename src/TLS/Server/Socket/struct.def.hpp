struct T
{
	T ();

	T (const TCP::Config::T & tcp_config);

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

static_assert (IO::IsWatchable::T <T>::value);
