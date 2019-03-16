struct T
{
	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	void
	cancel ();

	char
	get ();

	char
	peek ();

	bool
	eof ();

	static_assert (IsWatchable::T<T>::value);
	static_assert (Failure::TypeTraits::IsCancellable::T<T>::value);
	static_assert (IsInputStream::T<T>::value);
};
