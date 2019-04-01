struct T
{
	T (int file_descriptor);

	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	~T () = default;

	private:
	int file_descriptor;

	static_assert (TypeTraits::IsWatchable::T <T>::value);
};
