T::T (const Config::T & config)
:	ConnectionSocket::T
	(
		Util::client
		(
			config . getTCPConfig () . getHostname () -> data (),
			config . getTCPConfig () . getPort () -> data (),
			config . makeTLSConfig () . get (),
			config . getServerName () . data ()
		)
	)
{
}
