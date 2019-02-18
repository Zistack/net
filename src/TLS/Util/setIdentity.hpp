void
setIdentity (struct tls_config * tls_config,
    const char * private_key_filename,
    const char * certificate_filename)
{
	if (tls_config_set_key_file (tls_config, private_key_filename))
	{
		throw Failure::ResourceError::T (
		    std::string ("Failed to load private key file: ") +
		    tls_config_error (tls_config) + "\n");
	}

	if (tls_config_set_cert_file (tls_config, certificate_filename))
	{
		throw Failure::ResourceError::T (
		    std::string ("Failed to load certificate file: ") +
		    tls_config_error (tls_config) + "\n");
	}
}
