struct T
{
	T ();

	T (const Config::T & config);

	T (const T & other) = delete;

	T (T && other);

	T &
	operator = (const T & other) = delete;

	T &
	operator = (T && other);

	std::unique_ptr <Connection::Socket::T>
	accept ();

	IO::Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	~T ();

private:

	int m_file_descriptor;
};

static_assert (IO::IsWatchable::T <T>::value);
