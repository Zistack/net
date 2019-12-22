T::~T ()
{
	gnutls_priority_deinit (this -> m_priority);
}
