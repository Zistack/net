struct T : Socket::T
{
	T (int tcp_socket, struct tls * tls_context);

	T (const T & other) = delete;

	T (T && other) = delete;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = delete;

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
	IO::FileDescriptor::InputStream::T input_stream;
	IO::FileDescriptor::OutputStream::T output_stream;
	friend struct Connection::T;
};
