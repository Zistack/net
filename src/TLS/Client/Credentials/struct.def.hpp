struct T : TLS::Credentials::T
{
	T (const URI::Path::T & ca_path);

	T
	(
		const URI::Path::T & certificate_filename,
		const URI::Path::T & private_key_filename,
		const URI::Path::T & ca_path
	);

	T
	(
		const std::optional <TLS::KeyPair::T> & identity,
		const URI::Path::T & ca_path
	);

	~T () = default;
};
