void
T::setTransferEncoding (const NullableString::T & transfer_encoding)
{
	this -> set <Spec::TRANSFER_ENCODING> (transfer_encoding . optional ());
}
