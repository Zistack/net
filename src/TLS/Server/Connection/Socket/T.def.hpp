T::T (int tcp_socket, const Config::T & config)
:	T
	(
		tcp_socket,
		config . handshakeTimeout (),
		config . maxRecordSize (),
		config . identity (),
		config . caPath ()
	)
{
}

T::T
(
	int tcp_socket,
	std::chrono::nanoseconds handshake_timeout,
	size_t config_max_record_size,
	const KeyPair::T & identity,
	const std::optional <URI::Path::T> & ca_path
)
:	TLS::Socket::T <Specialization::T>
	(
		tcp_socket,
		GNUTLS_SERVER,
		handshake_timeout,
		config_max_record_size,
		identity,
		ca_path
	)
{
}
