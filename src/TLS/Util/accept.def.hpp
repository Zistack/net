std::pair <int, struct tls *>
accept (int server_socket, struct tls * server_context)
{
	struct tls * connection_context = nullptr;

	int connection_socket = TCP::Util::accept (server_socket);

	if
	(
		tls_accept_socket
		(
			server_context,
			& connection_context,
			connection_socket
		)
	)
	{
		throw Failure::Error::T
		(
			std::string ("Failed to create TLS connection: ") +
				tls_error (server_context) +
				"\n"
		);
	}

	return {connection_socket, connection_context};
}
