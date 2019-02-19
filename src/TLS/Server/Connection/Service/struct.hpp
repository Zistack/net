struct T : TLS::Connection::T
{
	T (IO::Interface::Protocol::T & connection_protocol,
	    const TLS::Connection::Config::Value::T & connection_config);

	~T () = default;
};
