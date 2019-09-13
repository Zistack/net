const TransferEncoding::Config::T &
T::transferEncodingConfig () const
{
	return this -> value <Spec::TRANSFER_ENCODING_CONFIG> ();
}

TransferEncoding::Config::T &
T::transferEncodingConfig ()
{
	return this -> value <Spec::TRANSFER_ENCODING_CONFIG> ();
}
