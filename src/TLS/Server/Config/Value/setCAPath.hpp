void
T::setCAPath (const std::optional<std::string> & ca_path)
{
	this->set<GetConfig::String::Type::T> (Spec::T::CA_PATH, ca_path);
}
