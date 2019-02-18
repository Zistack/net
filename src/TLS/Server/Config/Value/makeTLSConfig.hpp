std::unique_ptr<struct tls_config, Functor::T<tls_config_free>>
T::makeTLSConfig () const
{
	std::unique_ptr<struct tls_config, Functor::T<tls_config_free>> tls_config (
	    Util::config ());

	auto ca_path = this->getCAPath ();
	if (ca_path)
	{
		Util::setCAPath (tls_config.get (), ca_path->data ());
	}

	auto identity = this->getIdentity ();
	Util::setIdentity (tls_config.get (),
	    identity.getCertificateFilename ().data (),
	    identity.getPrivateKeyFilename ().data ());

	return tls_config;
}
