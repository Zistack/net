struct T : GetConfig::Section::Value::T<T, Spec::T::value>
{
	T (IO::Interface::PeekableInputStream::T & input_stream);

	void
	setTCPConfig (const TCP::Config::Value::T & tcp_config);

	TCP::Config::Value::T
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
	setIdentity (std::optional<KeyPair::Value::T> identity);

	std::optional<KeyPair::Value::T>
	getIdentity () const;

	void
	setConnectionConfig (
	    const Connection::Config::Value::T & connection_config);

	Connection::Config::Value::T
	getConnectionConfig () const;

	std::unique_ptr<struct tls_config, Functor::T<tls_config_free>>
	makeTLSConfig () const;
};
