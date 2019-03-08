struct T : Spec::T
{
	using InterfaceType = T;

	using Spec::T::T;

	void
	setTCPConfig (const TCP::Config::T & tcp_config);

	TCP::Config::T
	getTCPConfig () const;

	void
	setCAPath (const std::string & ca_path);

	std::string
	getCAPath () const;

	void
	setServerName (const std::string & server_name);

	std::string
	getServerName () const;

	void
	setIdentity (std::optional<KeyPair::T> identity);

	std::optional<KeyPair::T>
	getIdentity () const;

	std::unique_ptr<struct tls_config, Functor::T<tls_config_free>>
	makeTLSConfig () const;
};
