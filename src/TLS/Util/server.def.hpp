std::pair <int, struct tls *>
server
(
	const char * hostname,
	const char * port,
	struct tls_config * tls_config
)
{
	int server_socket = TCP::Util::server (hostname, port);

	struct tls * server_context = tls_server ();

	if (! server_context)
	{
		throw Failure::ResourceError::T ("Failed to create TLS server\n");
	}

	if (tls_configure (server_context, tls_config))
	{
		tls_free (server_context);
		throw Failure::ResourceError::T
		(
			std::string ("Failed to configure TLS server: ") +
				tls_config_error (tls_config) +
				"\n"
		);
	}

	return {server_socket, server_context};
}
