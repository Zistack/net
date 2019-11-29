T::T (const Config::T & config)
:	FIFOProtocol::Client::Protocol::T <T, Request::T, Response::T>
	(
		config . roundTripTimeout ()
	),
	m_input_timeout (config . inputTimeout ()),
	m_output_timeout (config . outputTimeout ()),
	m_transfer_encoding_config (config . transferEncodingConfig ()),
	m_temp_file_threshhold (config . tempFileThreshhold ())
{
}
