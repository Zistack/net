struct T
{
	T (int file_descriptor);

	T (int file_descriptor, size_t initial_position);

	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	size_t
	write (const char * buffer, size_t count);

	~T () = default;

private:

	int m_file_descriptor;
	size_t m_pointer;
};

static_assert (TypeTraits::IsWatchable::T <T>::value);
static_assert (TypeTraits::IsNonblockingOutputStream::T <T>::value);
