struct T
{
	T (Context::T & context,
	    IO::Interface::Watchable::T & input,
	    IO::Interface::Watchable::T & output);

	void
	accept (IO::Signal::T & signal);

	void
	connect (IO::Signal::T & signal);

	int
	read (char * buffer, int count, IO::Signal::T & signal);

	void
	write (char * buffer, int count, IO::Signal::T & signal);

	bool
	hasBufferedBytes ();

	void
	shutdown (IO::Signal::T & signal);

	~T () = default;

	void
	lock ();

	void
	unlock ();

	std::mutex mutex;
	std::condition_variable condition_variable;
	bool locked;

	::SSL * ssl;

	IO::Interface::Watchable::T & input;
	IO::Interface::Watchable::T & output;
};
