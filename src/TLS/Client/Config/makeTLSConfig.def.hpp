std::unique_ptr <struct tls_config, Functor::T <tls_config_free>>
T::makeTLSConfig () const
{
	std::unique_ptr
	<
		struct tls_config,
		Functor::T <tls_config_free>
	> tls_config (Util::config ());

	Util::setCAPath (tls_config . get (), this -> caPath () . data ());

	if (this -> identity ())
	{
		Util::setIdentity
		(
			tls_config . get (),
			this -> identity () -> certificateFilename () . data (),
			this -> identity () -> privateKeyFilename () . data ()
		);
	}

	return tls_config;
}
