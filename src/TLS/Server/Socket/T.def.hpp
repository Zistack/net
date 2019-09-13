T::T (const Config::T & config)
:	TLS::Socket::T
	(
		std::make_from_tuple <TLS::Socket::T>
		(
			Util::server
			(
				config . tcpConfig () . hostname () -> data (),
				config . tcpConfig () . port () -> data (),
				config . makeTLSConfig () . get ()
			)
		)
	)
{
}
