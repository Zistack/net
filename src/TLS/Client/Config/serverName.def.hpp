const std::optional <URI::Authority::Host::T> &
T::serverName () const
{
	return this -> value <Spec::SERVER_NAME> ();
}

std::optional <URI::Authority::Host::T> &
T::serverName ()
{
	return this -> value <Spec::SERVER_NAME> ();
}
