void
T::setTransferEncoding (const NullableString::T & transfer_encoding)
{
	this -> set <GetConfig::String::Type::T> (Spec::T::TRANSFER_ENCODING, transfer_encoding . optional ());
}
