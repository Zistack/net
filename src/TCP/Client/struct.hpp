struct T
{
	T (IO::Interface::Protocol::T & protocol,
	    std::string hostname,
	    std::string port,
	    IO::Interface::OutputStream::T * log);

	void
	run ();

	void
	stop ();

	~T ();

	IO::Interface::Protocol::T & protocol;

	IO::Signal::T * signal;
	IO::Socket::T * socket;

	IO::Interface::OutputStream::T * log;
};
