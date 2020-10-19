const Object::T &
T::objectAt (const std::string & name) const
{
	return this -> valueAt (name) . asObject ();
}

Object::T &
T::objectAt (const std::string & name)
{
	return this -> valueAt (name) . asObject ();
}
