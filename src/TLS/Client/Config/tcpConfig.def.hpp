const TCP::Config::T &
T::tcpConfig () const
{
	return this -> value <Spec::TCP_CONFIG> ();
}

TCP::Config::T &
T::tcpConfig ()
{
	return this -> value <Spec::TCP_CONFIG> ();
}
