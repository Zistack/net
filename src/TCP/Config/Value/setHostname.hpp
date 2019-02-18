void
T::setHostname (const NullableString::T & hostname)
{
	this->set<GetConfig::String::Type::T> (
	    Spec::T::HOSTNAME, hostname.optional ());
}
