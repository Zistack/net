T::T (const Config::T & config)
:	ConnectionSocket::T
	(
		Util::client
		(
			config . tcpConfig () . hostname () -> data (),
			config . tcpConfig () . port () -> data (),
			config . makeTLSConfig () . get (),
			config . serverName () . data ()
		)
	)
{
}
