T::T (const Config::T & config)
:	TCP::Socket::T
	(
		Util::client
		(
			config . getHostname () . cString (),
			config . getPort () . cString ()
		)
	)
{
}
