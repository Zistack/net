std::pair<int, struct tls *>
server (const char * hostname, const char * port)
{
	int server_socket = TCP::Util::server (hostname, port);

	struct tls * server_context = tls_server ();

	if (!server_context)
	{
		throw Failure::ResourceError::T ("Failed to create TLS server\n");
	}

	return {server_socket, server_context};
}
