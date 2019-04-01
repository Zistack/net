std::unique_ptr <struct tls_config, Functor::T <tls_config_free>>
T::makeTLSConfig () const
{
	std::unique_ptr
	<
		struct tls_config,
		Functor::T <tls_config_free>
	> tls_config (Util::config ());

	Util::setCAPath (tls_config . get (), this -> getCAPath () . data ());

	auto identity = this -> getIdentity ();
	if (identity)
	{
		Util::setIdentity
		(
			tls_config . get (),
			identity -> getCertificateFilename () . data (),
			identity -> getPrivateKeyFilename () . data ()
		);
	}

	return tls_config;
}
