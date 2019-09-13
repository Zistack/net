const std::string &
T::serverName () const
{
	return this -> value <Spec::SERVER_NAME> ();
}

std::string &
T::serverName ()
{
	return this -> value <Spec::SERVER_NAME> ();
}
