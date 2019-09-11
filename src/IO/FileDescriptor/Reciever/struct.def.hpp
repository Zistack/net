struct T
{
	T (int file_descriptor);

	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	size_t
	read (char * buffer, size_t count);

	~T () = default;

private:

	int m_file_descriptor;
};

static_assert (TypeTraits::IsWatchable::T <T>::value);
static_assert (TypeTraits::IsNonblockingInputStream::T <T>::value);
