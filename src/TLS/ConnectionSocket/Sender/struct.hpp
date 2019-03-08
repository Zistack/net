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

	void
	put (char c);

	void
	write (const char * buffer, size_t count);

	void
	print (const std::string & string);

	void
	cancel ();

	void
	clear ();

	private:
	void
	flush ();

	void
	send (const char * buffer, size_t count);

	void
	open ();

	void
	close ();

	int tcp_socket;
	struct tls * tls_context;
	Thread::SleepMutex::T & socket_mutex;
	bool & spurious_read;

	IO::CancelSignal::T cancel_signal;

	size_t next;

	static const size_t BUFFER_SIZE = 4096;

	std::unique_ptr<char[]> buffer;

	friend struct Scope::T<T>;
};
