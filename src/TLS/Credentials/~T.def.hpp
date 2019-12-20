T::~T ()
{
	gnutls_certificate_free_credentials (this -> m_credentials);
}
