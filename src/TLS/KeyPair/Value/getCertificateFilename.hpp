std::string
T::getCertificateFilename () const
{
	return this->get<GetConfig::String::Type::T> (Spec::T::CERTIFICATE_FILENAME)
	    .value ();
}
