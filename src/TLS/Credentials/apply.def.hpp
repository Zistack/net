void
T::apply (gnutls_session_t session, const T & credentials)
{
	int err = gnutls_credentials_set
	(
		session,
		GNUTLS_CRD_CERTIFICATE,
		credentials . m_credentials
	);
	if (err != GNUTLS_E_SUCCESS)
	{
		throw Failure::Error::T
		(
			std::string ("Failed to set credentials for TLS session: ") +
				gnutls_strerror (err) +
				"\n"
		);
	}
}

