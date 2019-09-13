const std::optional <std::string> &
T::port () const
{
	return this -> value <Spec::PORT> ();
}

std::optional <std::string> &
T::port ()
{
	return this -> value <Spec::PORT> ();
}
