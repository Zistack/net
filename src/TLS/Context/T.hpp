T::T (struct tls * tls_context) : tls_context (tls_context)
{
	const std::string message_prefix = "TLS::Context::T::T\n";

	if (!this->tls_context)
	{
		throw Failure::Error::T (
		    message_prefix + "Failed to initialize client context\n");
	}
}
