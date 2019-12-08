const GetConfig::Duration::T::Value &
T::handshakeTimeout () const
{
	return this -> value <Spec::HANDSHAKE_TIMEOUT> ();
}

GetConfig::Duration::T::Value &
T::handshakeTimeout ()
{
	return this -> value <Spec::HANDSHAKE_TIMEOUT> ();
}
