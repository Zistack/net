struct T
{
	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	size_t
	write (const char * buffer, size_t count);
};

static_assert (IsWatchable::T <T>::value);
static_assert (IsNonblockingOutputStream::T <T>::value);
