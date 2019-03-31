void
T::print (const std::string & string)
{
	this -> string . replace (this -> pointer, string . size (), string);

	this -> pointer += string . size ();
}
