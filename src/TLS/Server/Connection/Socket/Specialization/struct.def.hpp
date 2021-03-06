struct T
{
	T
	(
		gnutls_session_t session,
		const KeyPair::T & identity,
		const std::optional <URI::Path::T> & ca_path,
		const Ciphers::T & ciphers
	);

	~T () = default;

private:

	Credentials::T m_credentials;
};
