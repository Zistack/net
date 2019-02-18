std::string
T::getCAPath () const
{
	return this->get<GetConfig::String::Type::T> (Spec::T::CA_PATH).value ();
}
