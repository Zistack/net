T::T
(
	gnutls_session_t session,
	const std::optional <KeyPair::T> & identity,
	const URI::Path::T & ca_path,
	const URI::Authority::Host::T & server_name,
	size_t config_max_record_size
)
:	m_credentials (identity, ca_path),
	m_server_name (URI::Authority::Host::toString (server_name))
{
	TLS::Credentials::T::apply (session, this -> m_credentials);

	if (URI::Authority::Host::isRegisteredName (server_name))
	{
		Util::setServerName (session, this -> m_server_name);
	}

	gnutls_session_set_verify_cert
	(
		session,
		this -> m_server_name . data (),
		0
	);

	Util::setMaxRecordSize (session, config_max_record_size);
}
