struct T : GetConfig::Section::Value::T<T, Spec::T::value>
{
	using GetConfig::Section::Value::T<T, Spec::T::value>::T;

	void
	setTCPConfig (const TCP::Config::Value::T & tcp_config);

	TCP::Config::Value::T
	getTCPConfig () const;

	void
	setCAPath (const std::optional<std::string> & ca_path);

	std::optional<std::string>
	getCAPath () const;

	void
	setIdentity (const KeyPair::Value::T & identity);

	KeyPair::Value::T
	getIdentity () const;

	void
	setConnectionConfig (
	    const TLS::Connection::Config::Value::T & connection_config);

	TLS::Connection::Config::Value::T
	getConnectionConfig () const;

	std::unique_ptr<struct tls_config, Functor::T<tls_config_free>>
	makeTLSConfig () const;
};
