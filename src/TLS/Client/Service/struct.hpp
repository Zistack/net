struct T : TLS::Connection::T
{
	T (IO::Interface::Protocol::T & client_protcol,
	    std::chrono::milliseconds timeout,
	    Config::T & config);

	void
	run ();

	~T () = default;

	private:
	Config::T & config;
};
