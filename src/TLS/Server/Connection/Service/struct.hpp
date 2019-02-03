struct T : TLS::Connection::T
{
	T (IO::Interface::Protocol::T & connection_protocol,
	    std::chrono::milliseconds timeout);

	~T () = default;
};
