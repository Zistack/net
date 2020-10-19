const Array::T &
T::arrayAt (const std::string & name) const
{
	return this -> valueAt (name) . asArray ();
}

Array::T &
T::arrayAt (const std::string & name)
{
	return this -> valueAt (name) . asArray ();
}
