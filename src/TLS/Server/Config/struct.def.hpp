struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const TCP::Config::T &
	tcpConfig () const;

	TCP::Config::T &
	tcpConfig ();

	const std::optional <std::string> &
	caPath () const;

	std::optional <std::string> &
	caPath ();

	const KeyPair::T &
	identity () const;

	KeyPair::T &
	identity ();

	const GetConfig::Duration::T::Value &
	handshakeTimeout () const;

	GetConfig::Duration::T::Value &
	handshakeTimeout ();

	std::unique_ptr <struct tls_config, Functor::T <tls_config_free>>
	makeTLSConfig () const;
};
