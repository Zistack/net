struct T
{
	T (JSON::Value::T * json_value);
	T (std::list<std::pair<const char *, const char *>> public_private_keypairs,
	    const char * client_ca_filename,
	    const char * server_ca_filename,
	    const char * server_ca_path,
	    const char * cipher_string,
	    const char * dh_parameter_filename);

	void
	addIdentityKeyPair (const char * public_key_file,
	    const char * private_key_file);

	void
	setServerCA (const char * server_ca_filename, const char * server_ca_path);

	void
	setClientCA (const char * client_ca_filename);

	void
	setCipherString (const char * cipher_string);

	void
	setDHParameters (const char * dh_parameter_file);

	~T ();

	SSL_CTX * ssl_ctx;
};
