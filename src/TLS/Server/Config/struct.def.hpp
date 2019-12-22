struct T : Spec::T <T>
{
	using Spec::T <T>::T;

	const TCP::Config::T &
	tcpConfig () const;

	TCP::Config::T &
	tcpConfig ();

	const std::optional <URI::Path::T> &
	caPath () const;

	std::optional <URI::Path::T> &
	caPath ();

	const KeyPair::T &
	identity () const;

	KeyPair::T &
	identity ();

	const GetConfig::String::T::Value &
	cipherString () const;

	GetConfig::String::T::Value &
	cipherString ();

	const GetConfig::Duration::T::Value &
	handshakeTimeout () const;

	GetConfig::Duration::T::Value &
	handshakeTimeout ();

	const GetConfig::UInt::T::Value &
	maxRecordSize () const;

	GetConfig::UInt::T::Value &
	maxRecordSize ();
};
