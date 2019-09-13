const std::string &
T::certificateFilename () const
{
	return this -> value <Spec::CERTIFICATE_FILENAME> ();
}

std::string &
T::certificateFilename ()
{
	return this -> value <Spec::CERTIFICATE_FILENAME> ();
}
