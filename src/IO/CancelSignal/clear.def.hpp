void
T::clear ()
{
	if (this -> cancelled . exchange (false)) this -> signal . recieve ();
}
