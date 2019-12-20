const std::optional <URI::Authority::Host::T> &
T::hostname () const
{
	return this -> value <Spec::HOSTNAME> ();
}

std::optional <URI::Authority::Host::T> &
T::hostname ()
{
	return this -> value <Spec::HOSTNAME> ();
}
