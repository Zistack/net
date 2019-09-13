T::T (const Config::T & config)
:	TCP::Socket::T
	(
		Util::client
		(
			config . hostname () ? config . hostname () -> data () : nullptr,
			config . port () ? config . port () -> data () : nullptr
		)
	)
{
}
