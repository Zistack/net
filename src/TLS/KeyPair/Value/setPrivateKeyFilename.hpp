void
T::setPrivateKeyFilename (const std::string & private_key_filename)
{
	this->set<GetConfig::String::Type::T> (
	    Spec::T::PRIVATE_KEY_FILENAME, private_key_filename);
}
