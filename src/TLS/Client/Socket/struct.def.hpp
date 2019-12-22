struct T : TLS::Socket::T <Specialization::T>
{
	T (const Config::T & config, const Ciphers::T & ciphers);

	~T () = default;

private:

	T
	(
		const TCP::Config::T & tcp_config,
		std::chrono::nanoseconds handshake_timeout,
		size_t config_max_record_size,
		const std::optional <KeyPair::T> & identity,
		const URI::Path::T & ca_path,
		const URI::Authority::Host::T & server_name,
		const Ciphers::T & ciphers
	);
};
