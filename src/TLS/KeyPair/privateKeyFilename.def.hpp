const URI::Path::T &
T::privateKeyFilename () const
{
	return this -> value <Spec::PRIVATE_KEY_FILENAME> ();
}

URI::Path::T &
T::privateKeyFilename ()
{
	return this -> value <Spec::PRIVATE_KEY_FILENAME> ();
}
