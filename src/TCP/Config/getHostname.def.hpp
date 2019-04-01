NullableString::T
T::getHostname () const
{
	return {this -> get <Spec::HOSTNAME> ()};
}
