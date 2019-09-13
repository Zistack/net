const std::optional <std::string> &
T::caPath () const
{
	return this -> value <Spec::CA_PATH> ();
}

std::optional <std::string> &
T::caPath ()
{
	return this -> value <Spec::CA_PATH> ();
}
