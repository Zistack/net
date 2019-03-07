void
T::setHostname (const NullableString::T & hostname)
{
	this->set<Spec::HOSTNAME> (hostname.optional ());
}
