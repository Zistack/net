template <typename OutputStream>
void
T <OutputStream>::print (const std::string & string)
{
	this -> write (string . data (), string . size ());
}
