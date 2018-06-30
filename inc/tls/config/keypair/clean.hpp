void
clean (T * key_pair)
{
	delete key_pair->certificate_filename;
	delete key_pair->private_key_filename;
}
