T::T (JSON::Value::T * json_value)
{
	const std::string message_prefix = "TLS::Context::T\n";

	try
	{
		this->ssl_ctx = SSL_CTX_new (TLS_method ());

		if (!this->ssl_ctx) throw ProtocolError::T (getErrorMessage ());

		JSON::Object::T * config = json_value->asObject ();

		JSON::Value::T * identity_json = config->at ("Identity Certificates");
		if (identity_json)
		{
			for (auto key_pair : identity_json->asObject ()->members)
			{
				const char * public_key_filename = key_pair.first.data ();

				JSON::Value::T * private_json = key_pair.second;
				if (!private_json)
					throw ConfigError::T (
					    "Public key must be paired with private key");

				const char * private_key_filename =
				    private_json->asString ()->value.data ();

				this->addIdentityKeyPair (
				    public_key_filename, private_key_filename);
			}
		}

		JSON::Value::T * client_ca_filename = config->at ("Client CA");
		if (client_ca_filename)
		{
			this->setClientCA (client_ca_filename->asString ()->value.data ());
		}
		else
			this->setClientCA (nullptr);

		JSON::Value::T * server_ca = config->at ("Server CA");
		if (server_ca)
		{
			const char * server_ca_filename = nullptr;
			const char * server_ca_path = nullptr;

			JSON::Value::T * filename = server_ca->asObject ()->at ("File");
			if (filename)
				server_ca_filename = filename->asString ()->value.data ();

			JSON::Value::T * path = server_ca->asObject ()->at ("Path");
			if (path) server_ca_path = path->asString ()->value.data ();

			this->setServerCA (server_ca_filename, server_ca_path);
		}

		JSON::Value::T * cipher_string = config->at ("Ciphers");
		if (cipher_string)
			this->setCipherString (cipher_string->asString ()->value.data ());
		else
			throw ConfigError::T ("Cipher string must be provided");

		JSON::Value::T * dh_parameter_filename = config->at ("DH Parameters");
		if (dh_parameter_filename)
		{
			this->setDHParameters (
			    dh_parameter_filename->asString ()->value.data ());
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}

T::T (std::list<std::pair<const char *, const char *>> public_private_keypairs,
    const char * client_ca_filename,
    const char * server_ca_filename,
    const char * server_ca_path,
    const char * cipher_string,
    const char * dh_parameter_filename)
{
	for (auto public_private_keypair : public_private_keypairs)
	{
		const char * public_key_filename = public_private_keypair.first;
		const char * private_key_filename = public_private_keypair.second;
		this->addIdentityKeyPair (public_key_filename, private_key_filename);
	}

	this->setClientCA (client_ca_filename);
	this->setServerCA (server_ca_filename, server_ca_path);

	this->setCipherString (cipher_string);
	if (dh_parameter_filename) this->setDHParameters (dh_parameter_filename);
}
