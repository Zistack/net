void
T::setIdentity
(
	const URI::Path::T & certificate_file,
	const URI::Path::T & private_key_file
)
{
	int err = gnutls_certificate_set_x509_key_file
	(
		this -> m_credentials,
		certificate_file . toString () . data (),
		private_key_file . toString () . data (),
		GNUTLS_X509_FMT_PEM
	);
	if (err < 0)
	{
		throw Failure::Error::T
		(
			std::string ("Failed to set identity: ") +
				gnutls_strerror (err) +
				"\n"
		);
	}
}
