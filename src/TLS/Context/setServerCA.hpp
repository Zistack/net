void
T::setServerCA (const char * server_ca_filename, const char * server_ca_path)
{
	const std::string message_prefix = "TLS::Context::setServerCA\n";

	if (SSL_CTX_load_verify_locations (
	        this->ssl_ctx, server_ca_filename, server_ca_path) != 1)
	{
		throw ProtocolError::T (message_prefix + getErrorMessage ());
	}
}
