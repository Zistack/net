const std::string &
T::privateKeyFilename () const
{
	return this -> value <Spec::PRIVATE_KEY_FILENAME> ();
}

std::string &
T::privateKeyFilename ()
{
	return this -> value <Spec::PRIVATE_KEY_FILENAME> ();
}
