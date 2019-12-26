T::T (const TCP::Config::T & tcp_config)
:	host
	(
		tcp_config . hostname () ?
			* tcp_config . hostname () :
			URI::Authority::RegisteredName::T ("*"),
		tcp_config . port ()
	),
	using_default_port (tcp_config . port () == 80)
{
}

T::T (const TLS::Server::Config::T & tls_config)
:	host
	(
		tls_config . tcpConfig () . hostname () ?
			* tls_config . tcpConfig () . hostname () :
			URI::Authority::RegisteredName::T ("*"),
		tls_config . tcpConfig () . port ()
	),
	using_default_port (tls_config . tcpConfig () . port () == 443)
{
}
