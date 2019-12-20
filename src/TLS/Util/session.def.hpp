gnutls_session_t
session (unsigned int flags)
{
	gnutls_session_t session;

	int err = gnutls_init
	(
		& session,
		flags | GNUTLS_NONBLOCK | GNUTLS_POST_HANDSHAKE_AUTH
	);

	if (err != GNUTLS_E_SUCCESS)
	{
		throw Failure::Error::T
		(
			std::string ("Failed to create TLS session object: ") +
				gnutls_strerror (err) +
				"\n"
		);
	}

	return session;
}
