T::T (const NullableString::T & hostname, const NullableString::T & port)
{
	this->set<GetConfig::String::Type::T> ("Hostname", hostname.optional ());
	this->set<GetConfig::String::Type::T> ("Port", port.optional ());
}
