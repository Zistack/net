void
T::print (const std::string & string)
{
	this -> write (string . data (), string . size ());
}
