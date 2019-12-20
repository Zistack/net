struct T : TLS::Credentials::T
{
	T
	(
		const URI::Path::T & certificate_filename,
		const URI::Path::T & private_key_filename
	);

	T
	(
		const URI::Path::T & certificate_filename,
		const URI::Path::T & private_key_filename,
		const URI::Path::T & ca_path
	);

	T
	(
		const KeyPair::T & identity,
		const std::optional <URI::Path::T> & ca_path
	);

	~T () = default;
};
