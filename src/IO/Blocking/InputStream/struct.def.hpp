template <typename NonblockingInputStream>
struct T
{
	T (NonblockingInputStream input_stream);

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

	NonblockingInputStream m_input_stream;

	CancelSignal::T m_cancel_signal;

	size_t m_begin;
	size_t m_end;

	static const size_t BUFFER_SIZE = 4096;

	std::unique_ptr <char []> m_buffer;

	bool m_eof_bit;
};

template <typename NonblockingInputStream>
T (NonblockingInputStream && input_stream) -> T <NonblockingInputStream>;

static_assert
(
	IsWatchable::
		T <T <DummyNonblockingInputStream::T>>::
		value
);
static_assert
(
	Failure::
		TypeTraits::
		IsCancellable::
		T <T <DummyNonblockingInputStream::T>>::
		value
);
static_assert
(
	IsClearable::
		T <T <DummyNonblockingInputStream::T>>::
		value
);
static_assert
(
	IsBuffered::T <T <DummyNonblockingInputStream::T>>::value
);
static_assert
(
	IsInputStream::
		T <T <DummyNonblockingInputStream::T>>::
		value
);
