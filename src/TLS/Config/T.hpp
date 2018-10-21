T::T () : tls_config (tls_config_new ())
{
	const std::string message_prefix = "TLS::Config::T::T\n";

	if (!tls_config)
	{
		throw Failure::Error::T (
		    message_prefix + "Failed to create TLS configuration object\n");
	}
}
