struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const TCP::Config::T &
	tcpConfig () const;

	TCP::Config::T &
	tcpConfig ();

	const std::string &
	caPath () const;

	std::string &
	caPath ();

	const std::string &
	serverName () const;

	std::string &
	serverName ();

	const std::optional <KeyPair::T> &
	identity () const;

	std::optional <KeyPair::T> &
	identity ();

	std::unique_ptr<struct tls_config, Functor::T <tls_config_free>>
	makeTLSConfig () const;
};
