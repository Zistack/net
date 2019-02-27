void
T::setTransferEncodingConfig (
    const TransferEncoding::Encoder::Config::Value::T &
        transfer_encoding_config)
{
	this->set<TransferEncoding::Encoder::Config::Type::T> (
	    Spec::T::TRANSFER_ENCODING_CONFIG, transfer_encoding_config);
}
