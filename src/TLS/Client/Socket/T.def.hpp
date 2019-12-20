T::T (const Config::T & config)
:	T
	(
		config . tcpConfig (),
		config . handshakeTimeout (),
		config . maxRecordSize (),
		config . identity (),
		config . caPath (),
		config . serverName () ?
			* config . serverName () :
			* config . tcpConfig () . hostname ()
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
	const URI::Authority::Host::T & server_name
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
		config_max_record_size
	)
{
}
