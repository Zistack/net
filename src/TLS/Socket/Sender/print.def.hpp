template <typename Interface>
void
T <Interface>::print (const std::string & string)
{
	this -> write (string . data (), string . size ());
}
