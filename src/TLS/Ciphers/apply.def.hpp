void
T::apply (gnutls_session_t session, const T & ciphers)
{
	int err = gnutls_priority_set (session, ciphers . m_priority);
	if (err != GNUTLS_E_SUCCESS)
	{
		throw Failure::Error::T
		(
			std::string ("Failed to set ciphers for TLS session: ") +
				gnutls_strerror (err) +
				"\n"
		);
	}
}
