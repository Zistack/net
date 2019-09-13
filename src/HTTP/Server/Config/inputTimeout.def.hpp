const GetConfig::Duration::T::Value &
T::inputTimeout () const
{
	return this -> value <Spec::INPUT_TIMEOUT> ();
}

GetConfig::Duration::T::Value &
T::inputTimeout ()
{
	return this -> value <Spec::INPUT_TIMEOUT> ();
}
