void
T::configure (const Config::T & config)
{
	const std::string message_prefix =
	    "TLS::ConfigurableContext::T::configure\n";

	if (tls_configure (this->tls_context.get (), config.tls_config.get ()))
	{
		throw Failure::Error::T (message_prefix +
		    "Failed to configure TLS context: " +
		    tls_error (this->tls_context.get ()) + "\n");
	}
}
