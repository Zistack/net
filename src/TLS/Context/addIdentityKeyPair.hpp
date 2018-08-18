void
T::addIdentityKeyPair (const char * public_key_filename,
    const char * private_key_filename)
{
	const std::string message_prefix = "TLS::Context::addIdentityKeyPair\n";

	try
	{
		if (SSL_CTX_use_certificate_chain_file (
		        this->ssl_ctx, public_key_filename) != 1)
		{
			throw ProtocolError::T (getErrorMessage ());
		}

		if (SSL_CTX_use_PrivateKey_file (
		        this->ssl_ctx, private_key_filename, SSL_FILETYPE_PEM) != 1)
		{
			throw ProtocolError::T (getErrorMessage ());
		}

		if (SSL_CTX_check_private_key (this->ssl_ctx) != 1)
		{
			throw ProtocolError::T (getErrorMessage ());
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
