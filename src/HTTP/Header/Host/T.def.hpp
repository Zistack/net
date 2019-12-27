T::T (const std::string & field_value)
{
	IO::String::Reader::T input_stream (field_value);
	this -> host = URI::Authority::Rule::getHost (input_stream);
	if (IO::Util::test (input_stream, ':'))
	{
		input_stream . get ();
		this -> port = IO::Rule::getUInt (input_stream);
	}
	IO::Util::expectEOF (input_stream);
}

T::T
(
	const URI::Authority::Host::T & host,
	const std::optional <uint64_t> & port
)
: host (host), port (port)
{
}

T::T (const TCP::Config::T & tcp_config)
:	host
	(
		tcp_config . hostname () ?
			* tcp_config . hostname () :
			URI::Authority::RegisteredName::T ("*")
	),
	port (tcp_config . port ())
{
}

T::T (const TLS::Client::Config::T & tls_config)
:	host (tls_config . serverName ()),
	port (tls_config . tcpConfig () . port ())
{
}

T::T (const TLS::Server::Config::T & tls_config)
:	host
	(
		tls_config . tcpConfig () . hostname () ?
			* tls_config . tcpConfig () . hostname () :
			URI::Authority::RegisteredName::T ("*")
	),
	port (tls_config . tcpConfig () . port ())
{
}
