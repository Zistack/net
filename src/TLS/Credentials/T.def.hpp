T::T ()
{
	int err = gnutls_certificate_allocate_credentials (& this -> m_credentials);
	if (err != GNUTLS_E_SUCCESS)
	{
		throw Failure::Error::T
		(
			std::string ("Failed to create credentials object: ") +
				gnutls_strerror (err) +
				"\n"
		);
	}
}
