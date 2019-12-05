T::T (const Config::T & config)
:	FIFOProtocolInterface::T
	(
		config . inputTimeout (),
		config . outputTimeout (),
		config . roundTripTimeout (),
		config . transferEncodingConfig (),
		config . tempFileThreshhold ()
	)
{
}
