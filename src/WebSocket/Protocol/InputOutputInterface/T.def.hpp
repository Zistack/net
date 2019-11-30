template <typename Interface>
T <Interface>::T (const Config::T & config)
:	Input::T <T <Interface>>
	(
		config . inputTimeout (),
		config . closeTimeout (),
		config . tempFileThreshhold ()
	),
	Output::T (config . outputTimeout (), config . chunkSize ())
{
}
