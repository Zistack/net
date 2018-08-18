void
T::setClientCA (const char * client_ca_filename)
{
	const std::string message_prefix = "TLS::Context::setClientCA\n";

	if (client_ca_filename)
	{
		STACK_OF (X509_NAME) * ca_names =
		    SSL_load_client_CA_file (client_ca_filename);

		if (!ca_names)
			throw ProtocolError::T (message_prefix + getErrorMessage ());

		SSL_CTX_set_client_CA_list (this->ssl_ctx, ca_names);

		// It is currently unknown whether or not this call is necessary.
		sk_X509_NAME_pop_free (ca_names, X509_NAME_free);

		SSL_CTX_set_verify (this->ssl_ctx,
		    SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT,
		    NULL);
	}
	else
	{
		SSL_CTX_set_verify (this->ssl_ctx, SSL_VERIFY_PEER, NULL);
	}
}
