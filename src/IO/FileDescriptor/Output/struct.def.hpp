struct T
{
	T (int file_descriptor);

	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	~T () = default;

private:

	int m_file_descriptor;
};

static_assert (IsWatchable::T <T>::value);
