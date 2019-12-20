T::T
(
	const URI::Path::T & certificate_filename,
	const URI::Path::T & private_key_filename
)
{
	this -> setIdentity (certificate_filename, private_key_filename);
}

T::T
(
	const URI::Path::T & certificate_filename,
	const URI::Path::T & private_key_filename,
	const URI::Path::T & ca_path
)
{
	this -> setIdentity (certificate_filename, private_key_filename);
	this -> setCAPath (ca_path);
}

T::T (const KeyPair::T & identity, const std::optional <URI::Path::T> & ca_path)
{
	this -> setIdentity
	(
		identity . certificateFilename (),
		identity . privateKeyFilename ()
	);

	if (ca_path) this -> setCAPath (* ca_path);
}
