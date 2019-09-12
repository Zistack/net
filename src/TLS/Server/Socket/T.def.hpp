T::T (const Config::T & config)
:	TLS::Socket::T
	(
		std::make_from_tuple <TLS::Socket::T>
		(
			Util::server
			(
				config . getTCPConfig () . getHostname () -> data (),
				config . getTCPConfig () . getPort () -> data (),
				config . makeTLSConfig () . get ()
			)
		)
	)
{
}
