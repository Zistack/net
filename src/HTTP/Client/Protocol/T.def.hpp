T::T (const Config::T & config)
:	Base::T
	(
		config . getRoundTripTimeout (),
		config . getInputTimeout (),
		config . getOutputTimeout (),
		config . getTransferEncodingConfig (),
		config . getTempFileThreshhold ()
	)
{
}
