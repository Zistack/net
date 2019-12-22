const URI::Authority::Host::T &
T::serverName () const
{
	auto & explicit_server_name = this -> value <Spec::SERVER_NAME> ();
	if (explicit_server_name) return explicit_server_name . value ();
	else return this -> tcpConfig () . hostname () . value ();
}

URI::Authority::Host::T &
T::serverName ()
{
	auto & explicit_server_name = this -> value <Spec::SERVER_NAME> ();
	if (explicit_server_name) return explicit_server_name . value ();
	else return this -> tcpConfig () . hostname () . value ();
}
