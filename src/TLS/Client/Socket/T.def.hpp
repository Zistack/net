T::T (const Config::T & config, const Ciphers::T & ciphers)
:	T
	(
		config . tcpConfig (),
		config . handshakeTimeout (),
		config . maxRecordSize (),
		config . identity (),
		config . caPath (),
		config . serverName () ?
			* config . serverName () :
			* config . tcpConfig () . hostname (),
		ciphers
	)
{
}

T::T
(
	const TCP::Config::T & tcp_config,
	std::chrono::nanoseconds handshake_timeout,
	size_t config_max_record_size,
	const std::optional <KeyPair::T> & identity,
	const URI::Path::T & ca_path,
	const URI::Authority::Host::T & server_name,
	const Ciphers::T & ciphers
)
:	TLS::Socket::T <Specialization::T>
	(
		TCP::Util::client
		(
			tcp_config . hostname (),
			tcp_config . port ()
		),
		GNUTLS_CLIENT,
		handshake_timeout,
		config_max_record_size,
		identity,
		ca_path,
		server_name,
		ciphers,
		config_max_record_size
	)
{
}
