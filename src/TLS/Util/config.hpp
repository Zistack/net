struct tls_config *
config ()
{
	struct tls_config * tls_config = tls_config_new ();

	if (!tls_config)
	{
		throw Failure::ResourceError::T (
		    "Failed to create TLS configuration\n");
	}

	return tls_config;
}
