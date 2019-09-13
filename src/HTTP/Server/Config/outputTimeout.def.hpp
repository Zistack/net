const GetConfig::Duration::T::Value &
T::outputTimeout () const
{
	return this -> value <Spec::OUTPUT_TIMEOUT> ();
}

GetConfig::Duration::T::Value &
T::outputTimeout ()
{
	return this -> value <Spec::OUTPUT_TIMEOUT> ();
}
