T::T (const Config::T & config)
:	Base::T
	(
		config . roundTripTimeout (),
		config . inputTimeout (),
		config . outputTimeout (),
		config . transferEncodingConfig (),
		config . tempFileThreshhold ()
	)
{
}
