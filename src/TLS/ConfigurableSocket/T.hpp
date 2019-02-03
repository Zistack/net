T::T (const Config::T & config) : Context::T (nullptr)
{
	if (tls_configure (this->tls_context.get (), config.tls_config.get ()))
	{
		throw Failure::ResourceError::T ("Failed to configure TLS context: " +
		    tls_error (this->tls_context.get ()) + "\n");
	}
}
