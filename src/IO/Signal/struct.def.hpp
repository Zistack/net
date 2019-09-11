struct T
{
	T ();

	T (const T & other) = delete;

	T (T && other);

	T &
	operator = (const T & other) = delete;

	T &
	operator = (T && other);

	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	void
	send ();

	bool
	recieve ();

	~T ();

private:

	int m_file_descriptor;
};

static_assert (TypeTraits::IsWatchable::T <T>::value);
