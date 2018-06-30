int
init (T * context, Config::T * config)
{
	context->ssl_ctx = SSL_CTX_new (TLS_method ());
	if (!context->ssl_ctx)
	{
		ERR_print_errors_fp (stderr);
		return -1;
	}

	for (KeyPair key_pair : *config->self_certificate_pair_filenames)
	{
		if (SSL_CTX_use_certificate_chain_file (context->ssl_ctx,
		        key_pair->certificate_filename->data (),
		        SSL_FILETYPE_PEM) != 1)
		{
			ERR_print_errors_fp (stderr);
			goto error_0;
		}

		if (SSL_CTX_use_PrivateKey_file (context->ssl_ctx,
		        key_pair->private_key_filename->data (),
		        SSL_FILETYPE_PEM) != 1)
		{
			ERR_print_errors_fp (stderr);
			goto error_0;
		}

		if (SSL_CTX_check_private_key (context->ssl_ctx) != 1)
		{
			ERR_print_errors_fp (stderr);
			goto error_0;
		}
	}

	const char * server_CA_filename = NULL;
	const char * server_CA_path = NULL;
	if (config->server_CA_filename)
	{
		server_CA_filename = config->server_CA_filename->data ();
	}
	if (config->server_CA_path)
	{
		server_CA_path = config->server_CA_path->data ();
	}

	if (server_CA_filename || server_CA_path)
	{
		if (SSL_CTX_load_verify_locations (
		        context->ssl_ctx, server_CA_filename, server_CA_path) != 1)
		{
			ERR_print_errors_fp (stderr);
			goto error_0;
		}
	}

	if (config->client_certificate_authority_filename)
	{
		// This appears to be the only way that we load CAs from a file.
		STACK_OF (X509_NAME) * ca_names =
		    SSL_load_client_CA_file (client_CA_filename.data ());

		if (!ca_names)
		{
			ERR_print_errors_fp (stderr);
			goto error_0;
		}

		// Morover, we can only _set_ a list based on that.  We cannod add to a
		// database.
		SSL_CTX_set_client_CA_list (context->ssl_ctx, ca_names);

		// Do we have to deallocate this stack or the things inside of it?  IDK.
		sk_X509_NAME_pop_free (ca_names, X509_NAME_free);

		// We might want to set a flag for ourselves as well.
		SSL_CTX_set_verify (context->ssl_ctx,
		    SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT,
		    NULL);
	}
	else
	{
		SSL_CTX_set_verify (context->ssl_ctx, SSL_VERIFY_PEER, NULL);
	}

	if (SSL_CTX_set_cipher_list (
	        context->ssl_ctx, config->cipher_string->data ()))
	{
		ERR_print_errors_fp (stderr);
		goto error_0;
	}

	if (config->dh_param_filename)
	{
		DH * dh_params = NULL;

		FILE * dh_param_file = fopen (config->dh_param_filename, "r");

		if (!dh_param_file)
		{
			perror ("Could not open DH parameter file");
			goto error_0;
		}

		dh_params = PEM_read_DHparams (dh_param_file, NULL, NULL, NULL);

		fclose (dh_param_file);

		if (!dh_params)
		{
			ERR_print_errors_fp (stderr);
			goto error_0;
		}

		if (SSL_CTX_set_tmp_dh (context->ssl_ctx, dh_params) != 1)
		{
			// I'm mostly sure that this free call is a good idea.
			DH_free (dh_params);

			ERR_print_errors_fp (stderr);
			goto error_0;
		}

		// Do we actually need to do this?  IDK.
		DH_free (dh_params);
	}

	return 0;

error_0:
	SSL_CTX_free (context->ssl_ctx);
	context->ssl_ctx = NULL;
	return -1;
}
