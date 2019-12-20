const std::optional <URI::Path::T> &
T::caPath () const
{
	return this -> value <Spec::CA_PATH> ();
}

std::optional <URI::Path::T> &
T::caPath ()
{
	return this -> value <Spec::CA_PATH> ();
}
