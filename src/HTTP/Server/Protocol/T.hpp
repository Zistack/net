T::T (const Config::T & config, Responder::T & responder)
:	Base::T
	(
		config -> getInputTimeout (),
		config -> getOutputTimeout (),
		config -> getTransferEncodingConfig (),
		config -> getTempFileThreshhold (),
		responder
	)
{
}
