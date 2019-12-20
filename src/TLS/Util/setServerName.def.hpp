void
setServerName (gnutls_session_t session, const std::string & server_name)
{
	int err = gnutls_server_name_set
	(
		session,
		GNUTLS_NAME_DNS,
		server_name . data (),
		server_name . size ()
	);

	if (err != GNUTLS_E_SUCCESS)
	{
		throw Failure::Error::T
		(
			std::string ("Failed to set server name for TLS session: ") +
				gnutls_strerror (err) +
				"\n"
		);
	}
}
