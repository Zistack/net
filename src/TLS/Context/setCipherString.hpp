void
T::setCipherString (const char * cipher_string)
{
	const std::string message_prefix = "TLS::Context::setCipherString\n";

	if (SSL_CTX_set_cipher_list (this->ssl_ctx, cipher_string))
	{
		throw ProtocolError::T (message_prefix + getErrorMessage ());
	}
}
