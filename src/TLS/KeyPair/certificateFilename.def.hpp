const URI::Path::T &
T::certificateFilename () const
{
	return this -> value <Spec::CERTIFICATE_FILENAME> ();
}

URI::Path::T &
T::certificateFilename ()
{
	return this -> value <Spec::CERTIFICATE_FILENAME> ();
}
