void
T::apply (gnutls_session_t session, const T & credentials)
{
	Util::setCredentials (session, credentials . m_credentials);
}
