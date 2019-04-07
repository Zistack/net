void
T::setTransferEncodingConfig
(
	const TransferEncoding::Config::T & transfer_encoding_config
)
{
	this -> set<Spec::TRANSFER_ENCODING_CONFIG> (transfer_encoding_config);
}
