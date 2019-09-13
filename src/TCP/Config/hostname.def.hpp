const std::optional <std::string> &
T::hostname () const
{
	return this -> value <Spec::HOSTNAME> ();
}

std::optional <std::string> &
T::hostname ()
{
	return this -> value <Spec::HOSTNAME> ();
}
