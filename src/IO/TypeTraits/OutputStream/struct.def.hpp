struct T
{
	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	void
	cancel ();

	void
	put (char c);

	void
	write (const char * buffer, size_t count);

	void
	print (const std::string & string);
};

static_assert (IsWatchable::T <T>::value);
static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
static_assert (IsOutputStream::T <T>::value);
