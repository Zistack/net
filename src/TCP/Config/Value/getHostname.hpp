NullableString::T
T::getHostname () const
{
	return {this->get<GetConfig::String::Type::T> (Spec::T::HOSTNAME)};
}
