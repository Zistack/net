TransferEncoding::Encoder::Config::Value::T
T::getTransferEncodingConfig () const
{
	return this
	    ->get<TransferEncoding::Encoder::Config::Type::T> (
	        Spec::T::TRANSFER_ENCODING_CONFIG)
	    .value ();
}
