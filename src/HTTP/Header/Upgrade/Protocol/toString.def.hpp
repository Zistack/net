std::string
T::toString () const
{
	if (this -> version)
	{
		return this -> name + '/' + * this -> version;
	}
	else return this -> name;
}
