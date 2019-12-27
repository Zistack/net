T::T (const TCP::Config::T & tcp_config)
:	host (tcp_config),
	using_default_port (this -> host . port == 80)
{
}

T::T (const TLS::Server::Config::T & tls_config)
:	host (tls_config),
	using_default_port (this -> host . port == 443)
{
}
