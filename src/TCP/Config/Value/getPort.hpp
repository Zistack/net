NullableString::T
T::getPort () const
{
	return {this->get<GetConfig::String::Type::T> (Spec::T::PORT)};
}