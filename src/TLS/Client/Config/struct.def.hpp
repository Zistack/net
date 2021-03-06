struct T : Spec::T <T>
{
	T () = default;

	template
	<
		typename InputStream,
		typename = std::enable_if_t <IO::IsInputStream::T <InputStream>::value>
	>
	T (InputStream && input_stream);

	const TCP::Config::T &
	tcpConfig () const;

	TCP::Config::T &
	tcpConfig ();

	const URI::Path::T &
	caPath () const;

	URI::Path::T &
	caPath ();

	const URI::Authority::Host::T &
	serverName () const;

	URI::Authority::Host::T &
	serverName ();

	const std::optional <KeyPair::T> &
	identity () const;

	std::optional <KeyPair::T> &
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
