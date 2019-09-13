std::unique_ptr <struct tls_config, Functor::T <tls_config_free>>
T::makeTLSConfig () const
{
	std::unique_ptr
	<
		struct tls_config,
		Functor::T <tls_config_free>
	> tls_config (Util::config ());

	if (this -> caPath ())
	{
		Util::setCAPath (tls_config . get (), this -> caPath () -> data ());
	}

	Util::setIdentity
	(
		tls_config . get (),
		this -> identity () . certificateFilename () . data (),
		this -> identity () . privateKeyFilename () . data ()
	);

	return tls_config;
}
