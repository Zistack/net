std::pair<int, struct tls *>
client (const char * hostname, const char * port, const char * servername)
{
	int client_socket = TCP::Util::client (hostname, port);

	struct tls * client_context = tls_client ();

	if (!client_context)
	{
		throw Failure::ResourceError::T ("Failed to create TLS client\n");
	}

	if (tls_connect_socket (client_context, client_socket, servername))
	{
		throw Failure::ResourceError::T (
		    "Failed to establish TLS connection: " +
		    tls_error (client_context) + "\n");
	}

	return {client_socket, client_context};
}
