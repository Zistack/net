struct T : GetConfig::Section::Value::T<T, Spec::T::value>
{
	using GetConfig::Section::Value::T<T, Spec::T::value>::T;

	void
	setFIFOProtocolConfig (
	    const FIFOProtocol::Client::Config::Value::T & fifo_protocol_config);

	FIFOProtocol::Client::Config::Value::T
	getFIFOProtocolConfig () const;

	void
	setTransferEncodingConfig (
	    const TransferEncoding::Encoder::Config::Value::T &
	        transfer_encoding_config);

	TransferEncoding::Encoder::Config::Value::T
	getTransferEncodingConfig () const;

	void
	setTempFileThreshhold (uint64_t temp_file_threshhold);

	uint64_t
	getTempFileThreshhold () const;
};
