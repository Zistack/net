struct T
{
	T (const TCP::Config::T & tcp_config);

	T (const TLS::Server::Config::T & tls_config);

	~T () = default;

	Header::Host::T host;
	bool using_default_port;
};
