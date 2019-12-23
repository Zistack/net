struct T
{
	T (int file_descriptor);

	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	size_t
	write (const char * buffer, size_t count);

	~T () = default;

private:

	int m_file_descriptor;
};

static_assert (IsWatchable::T <T>::value);
static_assert (IsNonblockingOutputStream::T <T>::value);
