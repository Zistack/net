struct T : TLS::ConnectionSocket::T
{
	T (int tcp_socket, struct tls * connection_context);

	~T () = default;
};
