void
setCAPath (struct tls_config * tls_config, const char * ca_path)
{
	if (tls_config_set_ca_path (tls_config, ca_path))
	{
		throw Failure::ResourceError::T (
		    std::string ("Failed to set TLS config CA path: ") +
		    tls_config_error (tls_config) + "\n");
	}
}
