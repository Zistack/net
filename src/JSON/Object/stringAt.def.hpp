const String::T &
T::stringAt (const std::string & name) const
{
	return this -> valueAt (name) . asString ();
}

String::T &
T::stringAt (const std::string & name)
{
	return this -> valueAt (name) . asString ();
}
