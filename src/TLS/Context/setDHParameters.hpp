void
T::setDHParameters (const char * dh_parameter_filename)
{
	const std::string message_prefix = "TLS::Context::setDHParameters\n";

	try
	{
		FILE * dh_param_file = fopen (dh_parameter_filename, "r");

		if (!dh_param_file)
		{
			throw ProtocolError::T (
			    std::string ("fopen: ") + strerror (errno) + "\n");
		}

		DH * dh_params = PEM_read_DHparams (dh_param_file, NULL, NULL, NULL);

		fclose (dh_param_file);

		if (!dh_params) throw ProtocolError::T (getErrorMessage ());

		if (SSL_CTX_set_tmp_dh (this->ssl_ctx, dh_params) != 1)
			throw ProtocolError::T (getErrorMessage ());

		// Maybe we need to do this?
		DH_free (dh_params);
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
