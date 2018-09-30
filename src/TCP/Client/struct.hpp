struct T
{
	T (const char * hostname,
	    const char * port,
	    IO::Interface::OutputStream::T * log,
	    IO::Interface::Protocol::T * protocol);

	void
	run ();

	void
	stop ();

	~T ();

	const char * hostname;
	const char * port;

	IO::Interface::OutputStream::T * log;

	IO::Interface::Protocol::T * protocol;
};
