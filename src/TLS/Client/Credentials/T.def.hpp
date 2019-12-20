T::T (const URI::Path::T & ca_path)
{
	this -> setCAPath (ca_path);
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

T::T
(
	const std::optional <TLS::KeyPair::T> & identity,
	const URI::Path::T & ca_path
)
{
	if (identity)
	{
		this -> setIdentity
		(
			identity -> certificateFilename (),
			identity -> privateKeyFilename ()
		);
	}

	this -> setCAPath (ca_path);
}
