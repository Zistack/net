const URI::Path::T &
T::caPath () const
{
	return this -> value <Spec::CA_PATH> ();
}

URI::Path::T &
T::caPath ()
{
	return this -> value <Spec::CA_PATH> ();
}
