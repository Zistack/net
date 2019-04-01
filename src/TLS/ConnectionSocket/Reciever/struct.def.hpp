struct T
{
	T
	(
		int tcp_socket,
		struct tls * tls_context,
		Thread::SleepMutex::T & socket_mutex,
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

	int tcp_socket;
	struct tls * tls_context;
	Thread::SleepMutex::T & socket_mutex;
	bool & spurious_read;

	IO::CancelSignal::T cancel_signal;

	size_t begin;
	size_t end;

	static const size_t BUFFER_SIZE = 4096;

	std::unique_ptr <char []> buffer;

	bool eof_bit;

	static_assert (IO::TypeTraits::IsWatchable::T <T>::value);
	static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
	static_assert (IO::TypeTraits::IsClearable::T <T>::value);
	static_assert (IO::TypeTraits::IsBuffered::T <T>::value);
	static_assert (IO::TypeTraits::IsSpurious::T <T>::value);
	static_assert (IO::TypeTraits::IsInputStream::T <T>::value);
};
