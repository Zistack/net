struct T : TLS::Connection::T
{
	T (IO::Interface::Protocol::T & client_protcol,
	    std::chrono::milliseconds timeout,
	    Config::Value::T & config);

	void
	run ();

	~T () = default;

	private:
	Config::Value::T & config;
};
