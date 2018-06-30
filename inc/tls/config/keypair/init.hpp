void
init (T * key_pair,
    std::string * certificate_filename,
    std::string * private_key_filename)
{
	key_pair->certificate_filename = new std::string (certificate_filename);
	key_pair->private_key_filename = new std::string (private_key_filename);
}
