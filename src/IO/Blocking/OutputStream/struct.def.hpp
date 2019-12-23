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

	NonblockingOutputStream m_output_stream;
	CancelSignal::T m_cancel_signal;

	size_t m_next;

	static const size_t BUFFER_SIZE = 4096;

	std::unique_ptr <char []> m_buffer;

	friend struct BufferedOutputScope::T <T>;
};

template <typename NonblockingOutputStream>
T (NonblockingOutputStream && output_stream) -> T <NonblockingOutputStream>;

static_assert
(
	IsWatchable::
		T <T <DummyNonblockingOutputStream::T>>::
		value
);
static_assert
(
	Failure::
		TypeTraits::
		IsCancellable::
		T <T <DummyNonblockingOutputStream::T>>::
		value
);
static_assert
(
	IsClearable::
		T <T <DummyNonblockingOutputStream::T>>::
		value
);
static_assert
(
	IsOutputStream::
		T <T <DummyNonblockingOutputStream::T>>::
		value
);
static_assert
(
	IsBuffered::
		T <T <DummyNonblockingOutputStream::T>>::
		value
);
