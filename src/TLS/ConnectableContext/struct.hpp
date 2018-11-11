struct T : virtual Context::T
{
	T (IO::Interface::NonblockingInputStream::T & input,
	    IO::Interface::NonblockingOutputStream::T & output);

	T (const T & other) = delete;

	T (const T && other) = delete;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (const T && other) = delete;

	virtual void
	connect (IO::Signal::T & signal) = 0;

	size_t
	read (char * buffer, size_t count, IO::Signal::T & signal);

	bool
	write (char * buffer, size_t count, IO::Signal::T & signal);

	void
	close (IO::Signal::T & signal);

	virtual ~T () = default;

	protected:
	void
	handshake (IO::Signal::T & signal);

	IO::Interface::Watchable::T & input;
	IO::Interface::Watchable::T & output;
};
