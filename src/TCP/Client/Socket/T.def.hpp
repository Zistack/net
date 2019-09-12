T::T (const Config::T & config)
:	TCP::Socket::T
	(
		Util::client
		(
			config . getHostname () ?
				config . getHostname () -> data () :
				nullptr,
			config . getPort () ? config . getPort () -> data () : nullptr
		)
	)
{
}
