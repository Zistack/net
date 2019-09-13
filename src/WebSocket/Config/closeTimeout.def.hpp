const GetConfig::Duration::T::Value &
T::closeTimeout () const
{
	return this -> value <Spec::CLOSE_TIMEOUT> ();
}

GetConfig::Duration::T::Value &
T::closeTimeout ()
{
	return this -> value <Spec::CLOSE_TIMEOUT> ();
}
