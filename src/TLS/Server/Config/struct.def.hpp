struct T : Spec::T
{
	using Value = T;

	using Spec::T::T;

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

	std::unique_ptr <struct tls_config, Functor::T <tls_config_free>>
	makeTLSConfig () const;
};
