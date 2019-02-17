void
T::setHostname (const NullableString::T & hostname)
{
	this->set<GetConfig::String::Type::T> ("Hostname", hostname.optional ());
}
