void
init (T * config)
{
	config->self_keypair_filenames = new std::list<KeyPair::T> ();
	config->client_CA_filename = NULL;
	config->server_CA_filename = NULL;
	config->server_CA_path = NULL;
	config->cipher_string = NULL;
	config->dh_param_filename = NULL;
}
