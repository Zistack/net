struct T : Spec::T
{
	using InterfaceType = T;

	using Spec::T::T;

	void
	setTCPConfig (const TCP::Config::T & tcp_config);

	TCP::Config::T
	getTCPConfig () const;

	void
	setCAPath (const std::optional<std::string> & ca_path);

	std::optional<std::string>
	getCAPath () const;

	void
	setIdentity (const KeyPair::T & identity);

	KeyPair::T
	getIdentity () const;

	std::unique_ptr<struct tls_config, Functor::T<tls_config_free>>
	makeTLSConfig () const;
};
