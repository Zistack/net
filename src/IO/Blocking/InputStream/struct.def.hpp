template <typename NonblockingInputStream>
struct T
{
	T (NonblockingInputStream input_stream);

	Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	void
	cancel ();

	void
	clear ();

	bool
	isReady () const;

	char
	get ();

	char
	peek ();

	bool
	eof ();

	~T () = default;

	private:
	void
	refill ();

	NonblockingInputStream input_stream;

	CancelSignal::T cancel_signal;

	size_t begin;
	size_t end;

	static const size_t BUFFER_SIZE = 4096;

	std::unique_ptr <char []> buffer;

	bool eof_bit;

	static_assert (TypeTraits::IsWatchable::T <T>::value);
	static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
	static_assert (TypeTraits::IsClearable::T <T>::value);
	static_assert (TypeTraits::IsBuffered::T <T>::value);
	static_assert (TypeTraits::IsInputStream::T <T>::value);
};

template <typename NonblockingInputStream>
T (NonblockingInputStream && input_stream) -> T <NonblockingInputStream>;
