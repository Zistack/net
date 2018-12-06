std::string &
T::stdString ()
{
	return this->string.value ();
}

const std::string &
T::stdString () const
{
	return this->string.value ();
}
