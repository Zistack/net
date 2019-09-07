std::string
T::toString () const
{
	if (this -> version)
	{
		return this -> name + '/' + this -> version . stdString ();
	}
	else return this -> name;
}
