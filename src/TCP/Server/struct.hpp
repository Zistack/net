struct T
{
	T (const char * hostname,
	    const char * port,
	    IO::Interface::OutputStream::T * log,
	    IO::Interface::ProtocolFactory::T * protocol_factory);

	void
	run ();

	void
	stop ();

	~T () = default;

	const char * hostname;
	const char * port;
	IO::Interface::OutputStream::T * log;

	IO::Interface::ProtocolFactory::T * protocol_factory;

	Shutdown::Signal::T shutdown_signal;
};
