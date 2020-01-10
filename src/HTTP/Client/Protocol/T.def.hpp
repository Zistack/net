template <typename Interface>
T <Interface>::T (const Config::T & config)
:	FIFOProtocolInterface::T <Interface>
	(
		config . inputTimeout (),
		config . outputTimeout (),
		config . roundTripTimeout (),
		config . transferEncodingConfig (),
		config . tempFileThreshhold ()
	)
{
}
