void
T::setServerName (const std::string & server_name)
{
	this->set<GetConfig::String::Type::T> (Spec::T::SERVER_NAME, server_name);
}
