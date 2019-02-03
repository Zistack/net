struct T : virtual Context::T
{
	// We have to be able to watch for input and output separately, even though
	// we've got all of one file descriptor.
	T ();

	T (const T & other) = delete;

	T (const T && other) = delete;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (const T && other) = delete;

	void
	handshake (IO::Interface::Watchable::T & cancel_signal);

	size_t
	read (char * buffer,
	    size_t count,
	    IO::Interface::Watchable::T & cancel_signal);

	bool
	write (char * buffer,
	    size_t count,
	    IO::Interface::Watchable::T & cancel_signal);

	void
	close (IO::Interface::Watchable::T & cancel_signal);

	virtual ~T () = default;

	protected:
	IO::Interface::NonblockingInputStream::T & input_stream;
	IO::Interface::NonblockingOutputStream::T & output_stream;
};
