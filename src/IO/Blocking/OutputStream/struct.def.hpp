template <typename NonblockingOutputStream>
struct T
{
	T (NonblockingOutputStream output_stream);

	T (T && other) = default;

	T &
	operator = (T && other) = default;

	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	void
	cancel ();

	void
	clear ();

	void
	put (char c);

	void
	write (const char * buffer, size_t count);

	void
	print (const std::string & string);

	~T () = default;

private:

	void
	flush ();

	void
	send (const char * buffer, size_t count);

	void
	open ();

	void
	close ();

	NonblockingOutputStream output_stream;
	CancelSignal::T cancel_signal;

	size_t next;

	static const size_t BUFFER_SIZE = 4096;

	std::unique_ptr <char []> buffer;

	friend struct Scope::T <T>;

	static_assert (TypeTraits::IsWatchable::T <T>::value);
	static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
	static_assert (TypeTraits::IsClearable::T <T>::value);
	static_assert (TypeTraits::IsOutputStream::T <T>::value);
	static_assert (TypeTraits::IsBuffered::T <T>::value);
};

template <typename NonblockingOutputStream>
T (NonblockingOutputStream && output_stream) -> T <NonblockingOutputStream>;
