struct T
{
	T (IO::Interface::Protocol::T * protocol,
	    IO::Signal::T * signal,
	    IO::Socket::T * socket,
	    IO::Interface::OutputStream::T * log);

	void
	run ();

	~T () = default;

	IO::Interface::Protocol::T * protocol;

	IO::Signal::T * signal;
	IO::Socket::T * socket;

	IO::Interface::OutputStream::T * log;
};
