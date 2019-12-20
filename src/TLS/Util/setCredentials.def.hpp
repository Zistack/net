void
setCredentials
(
	gnutls_session_t session,
	gnutls_certificate_credentials_t credentials
)
{
	int err = gnutls_credentials_set
	(
		session,
		GNUTLS_CRD_CERTIFICATE,
		credentials
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
