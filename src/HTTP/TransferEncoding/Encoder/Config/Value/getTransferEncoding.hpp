NullableString::T
T::getTransferEncoding () const
{
	return {this -> get <GetConfig::String::Type::T> (Spec::T::TRANSFER_ENCODING)};
}
