void
T::set (const char * string)
{
	if (string)
		this->string = std::string (string);
	else
		this->string.reset ();
}

void
T::set (const std::string & string)
{
	this->string = string;
}
