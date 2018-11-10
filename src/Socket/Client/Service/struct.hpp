struct T
{
	T (IO::Interface::Protocol::T & client_protocol);

	void
	prime ();

	void
	run ();

	void
	stop ();

	virtual ~T () = default;

	protected:
	virtual std::unique_ptr<IO::Interface::Socket::T>
	newSocket () = 0;

	private:
	// Given members

	IO::Interface::Protocol::T & client_protocol;

	// Transient members

	std::unique_ptr<IO::Interface::Socket::T> socket;
};
