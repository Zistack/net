T::T ()
{
}

T::T (const char * string)
{
	if (string) this -> string = std::string (string);
}

T::T (const std::string & string) : string (string)
{
}

T::T (const std::optional <std::string> & string) : string (string)
{
}
