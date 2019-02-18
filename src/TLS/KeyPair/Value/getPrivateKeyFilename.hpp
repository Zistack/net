std::string
T::getPrivateKeyFilename () const
{
	return this->get<GetConfig::String::Type::T> (Spec::T::PRIVATE_KEY_FILENAME)
	    .value ();
}
