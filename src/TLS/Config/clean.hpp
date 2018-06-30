void
clean (T * config)
{
	for (KeyPair * key_pair : config->self_key_pair_filenames)
	{
		KeyPair::destroy (key_pair);
	}

	delete config->self_key_pair_filenames;

	if (config->client_ca_filename) delete config->client_ca_filename;
	if (config->server_ca_filename) delete config->server_ca_filename;
	if (config->server_ca_path) delete config->server_ca_path;
	if (config->cipher_string) delete config->cipher_string;
	if (config->dh_param_filename) delete config->dh_param_filename;
}
