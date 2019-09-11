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

	void
	put (char c);

	void
	write (const char * buffer, size_t count);

	void
	print (const std::string & string);

private:

	void
	flush ();

	void
	send (const char * buffer, size_t count);

	void
	open ();

	void
	close ();

	int m_tcp_socket;
	struct tls * m_tls_context;
	std::mutex & m_socket_mutex;
	bool & m_spurious_read;

	IO::CancelSignal::T m_cancel_signal;

	size_t m_next;

	static const size_t BUFFER_SIZE = 4096;

	std::unique_ptr <char []> m_buffer;

	friend struct Scope::T <T>;
};

static_assert (IO::TypeTraits::IsWatchable::T <T>::value);
static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
static_assert (IO::TypeTraits::IsClearable::T <T>::value);
static_assert (IO::TypeTraits::IsOutputStream::T <T>::value);
static_assert (IO::TypeTraits::IsBuffered::T <T>::value);
