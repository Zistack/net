struct T
{
	T ();

	T (T && other);

	T &
	operator = (T && other);

	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	void
	cancel ();

	void
	clear ();

	~T () = default;

	private:
	std::atomic <bool> cancelled;
	Signal::T signal;

	static_assert (TypeTraits::IsWatchable::T <T>::value);
	static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
	static_assert (TypeTraits::IsClearable::T <T>::value);
};
