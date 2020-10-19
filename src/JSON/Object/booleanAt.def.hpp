const Boolean::T &
T::booleanAt (const std::string & name) const
{
	return this -> valueAt (name) . asBoolean ();
}

Boolean::T &
T::booleanAt (const std::string & name)
{
	return this -> valueAt (name) . asBoolean ();
}
