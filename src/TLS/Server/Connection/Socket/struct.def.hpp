struct T : TLS::Socket::T <Specialization::T>
{
	T (int tcp_socket, const Config::T & config);

	~T () = default;

private:

	T
	(
		int tcp_socket,
		std::chrono::nanoseconds handshake_timeout,
		size_t config_max_record_size,
		const KeyPair::T & identity,
		const std::optional <URI::Path::T> & ca_path
	);
};
