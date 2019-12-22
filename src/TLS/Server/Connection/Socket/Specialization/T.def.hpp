T::T
(
	gnutls_session_t session,
	const KeyPair::T & identity,
	const std::optional <URI::Path::T> & ca_path,
	const Ciphers::T & ciphers
)
:	m_credentials (identity, ca_path)
{
	TLS::Credentials::T::apply (session, this -> m_credentials);

	gnutls_certificate_server_set_request
	(
		session,
		ca_path ? GNUTLS_CERT_REQUIRE : GNUTLS_CERT_IGNORE
	);

	Ciphers::T::apply (session, ciphers);
}
