struct T
{
	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	size_t
	read (char * buffer, size_t count);
};

static_assert (IsWatchable::T <T>::value);
static_assert (IsNonblockingInputStream::T <T>::value);
