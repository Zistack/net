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

	int file_descriptor;

	private:
	static_assert (TypeTraits::IsWatchable::T<T>::value);
	static_assert (TypeTraits::IsNonblockingOutputStream::T<T>::value);
};
