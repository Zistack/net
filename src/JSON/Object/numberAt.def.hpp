const Number::T &
T::numberAt (const std::string & name) const
{
	return this -> valueAt (name) . asNumber ();
}

Number::T &
T::numberAt (const std::string & name)
{
	return this -> valueAt (name) . asNumber ();
}
