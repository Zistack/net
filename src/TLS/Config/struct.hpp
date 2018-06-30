struct T
{
	std::list<KeyPair::T *> * self_key_pair_filenames;
	std::string * client_ca_filename;
	std::string * server_ca_filename;
	std::string * server_ca_path;
	std::string * cipher_string;
	std::string * dh_param_filename;
};
