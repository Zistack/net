T::T (const Config::T & config) : Context::T (nullptr)
{
	const std::string message_prefix = "TLS::ConfigurableContext::T::T\n";

	if (tls_configure (this->tls_context.get (), config.tls_config.get ()))
	{
		throw Failure::Error::T (message_prefix +
		    "Failed to configure TLS context: " +
		    tls_error (this->tls_context.get ()) + "\n");
	}
}
