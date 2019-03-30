template <typename Element>
void
T <Element>::cancel ()
{
	this -> close ();
	this -> flush ();
}
