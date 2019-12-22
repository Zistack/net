struct T
{
	T
	(
		gnutls_session_t session,
		const std::optional <KeyPair::T> & identity,
		const URI::Path::T & ca_path,
		const URI::Authority::Host::T & server_name,
		const Ciphers::T & ciphers,
		size_t config_max_record_size
	);

	~T () = default;

private:

	const Credentials::T m_credentials;
	const std::string m_server_name;
};
