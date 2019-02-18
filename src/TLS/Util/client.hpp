std::pair<int, struct tls *>
client (const char * hostname,
    const char * port,
    struct tls_config * tls_config,
    const char * servername)
{
	int client_socket = TCP::Util::client (hostname, port);

	struct tls * client_context = tls_client ();

	if (!client_context)
	{
		throw Failure::ResourceError::T ("Failed to create TLS client\n");
	}

	if (tls_configure (client_context, tls_config))
	{
		tls_free (client_context);
		throw Failure::ResourceError::T (
		    std::string ("Failed to configure TLS client: ") +
		    tls_config_error (tls_config) + "\n");
	}

	if (tls_connect_socket (client_context, client_socket, servername))
	{
		tls_free (client_context);
		throw Failure::ResourceError::T (
		    std::string ("Failed to establish TLS connection: ") +
		    tls_error (client_context) + "\n");
	}

	return {client_socket, client_context};
}
