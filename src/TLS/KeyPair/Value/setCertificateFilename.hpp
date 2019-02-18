void
T::setCertificateFilename (const std::string & certificate_filename)
{
	this->set<GetConfig::String::Type::T> (
	    Spec::T::CERTIFICATE_FILENAME, certificate_filename);
}
