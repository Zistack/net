struct T
{
	T
	(
		int tcp_socket,
		struct tls * tls_context,
		std::mutex & socket_mutex,
		bool & spurious_read
	);

	IO::Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	void
	cancel ();

	void
	clear ();

	bool
	isReady () const;

	bool
	spurious ();

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

	int m_tcp_socket;
	struct tls * m_tls_context;
	std::mutex & m_socket_mutex;
	bool & m_spurious_read;

	IO::CancelSignal::T m_cancel_signal;

	size_t m_begin;
	size_t m_end;

	static const size_t BUFFER_SIZE = 4096;

	std::unique_ptr <char []> m_buffer;

	bool m_eof_bit;
};

static_assert (IO::TypeTraits::IsWatchable::T <T>::value);
static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
static_assert (IO::TypeTraits::IsClearable::T <T>::value);
static_assert (IO::TypeTraits::IsBuffered::T <T>::value);
static_assert (IO::TypeTraits::IsSpurious::T <T>::value);
static_assert (IO::TypeTraits::IsInputStream::T <T>::value);
