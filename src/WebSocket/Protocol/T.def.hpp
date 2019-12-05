template <typename Interface>
T <Interface>::T (const Config::T & config)
:	InputOutputInterface::T <Interface>
	(
		config . inputTimeout (),
		config . outputTimeout (),
		config . closeTimeout (),
		config . chunkSize (),
		config . tempFileThreshhold ()
	)
{
}
