T::T () : file_descriptor (-1)
{
}

T::T (const Config::T & config)
:	file_descriptor
	(
		Util::server
		(
			config . getHostname () . cString (),
			config . getPort () . cString ()
		)
	)
{
}

T::T (T && other) : file_descriptor (other . file_descriptor)
{
	other . file_descriptor = -1;
}
