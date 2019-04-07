NullableString::T
T::getTransferEncoding () const
{
	return {this -> get <Spec::TRANSFER_ENCODING> ()};
}
