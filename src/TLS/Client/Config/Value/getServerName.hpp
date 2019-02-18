std::string
T::getServerName () const
{
	return this->get<GetConfig::String::Type::T> (Spec::T::SERVER_NAME)
	    .value ();
}
