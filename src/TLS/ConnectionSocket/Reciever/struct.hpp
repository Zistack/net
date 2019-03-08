struct T
{
	T (int tcp_socket,
	    struct tls * tls_context,
	    Thread::SleepMutex::T & socket_mutex,
	    bool & spurious_read);

	IO::Interface::Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	char
	get ();

	char
	peek ();

	bool
	eof ();

	void
	cancel ();

	void
	clear ();

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

	std::unique_ptr<char[]> buffer;

	bool eof_bit;
};
