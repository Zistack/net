void
T::setCAPath (const URI::Path::T & ca_path)
{
	int err = gnutls_certificate_set_x509_trust_dir
	(
		this -> m_credentials,
		ca_path . toString () . data (),
		GNUTLS_X509_FMT_PEM
	);
	if (err < 1)
	{
		// The documentation seems to indicate that this function won't report
		// errors, but may simply not load any certificates.

		throw Failure::ResourceError::T
		(
			"Failed to set CA Path: No certificates could be loaded.\n"
		);
	}
}
