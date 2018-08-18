T::T (Context::T & context,
    IO::Interface::Watchable::T & input,
    IO::Interface::Watchable::T & output) :
    input (input),
    output (output)
{
	const std::string message_prefix = "TLS::SSL::T\n";

	try
	{
		this->ssl = SSL_new (context.ssl_ctx);

		if (!this->ssl) throw ProtocolError::T (getErrorMessage ());

		if (!SSL_set_rfd (this->ssl, input.fileDescriptor ()))
		{
			SSL_free (this->ssl);
			throw ProtocolError::T (getErrorMessage ());
		}

		if (!SSL_set_wfd (this->ssl, output.fileDescriptor ()))
		{
			SSL_free (this->ssl);
			throw ProtocolError::T (getErrorMessage ());
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
