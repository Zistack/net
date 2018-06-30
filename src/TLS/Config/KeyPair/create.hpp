T *
create (std::string * certificate_filename, std::string * private_key_filename)
{
	T * key_pair = (T *) malloc (sizeof (T));
	init (key_pair, certificate_filename, private_key_filename);
	return key_pair;
}
