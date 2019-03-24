T &
T::operator = (const char * string)
{
	this -> set (string);
	return * this;
}

T &
T::operator = (const std::string & string)
{
	this -> set (string);
	return * this;
}

T &
T::operator = (const std::optional <std::string> & string)
{
	this -> set (string);
	return * this;
}
