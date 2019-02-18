void
T::setPort (const NullableString::T & port)
{
	this->set<GetConfig::String::Type::T> (Spec::T::PORT, port.optional ());
}
