struct T
{
	T () = default;

	T (const std::string & field_value);

	T
	(
		const URI::Authority::Host::T & host,
		const std::optional <uint64_t> & port
	);

	T (const TCP::Config::T & tcp_config);

	T (const TLS::Client::Config::T & tls_config);

	T (const TLS::Server::Config::T & tls_config);

	bool
	match (const URI::T & uri);

	std::string
	toString () const;

	~T () = default;

	URI::Authority::Host::T host;
	std::optional <uint64_t> port;
};
