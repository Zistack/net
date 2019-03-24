const char *
T::cString () const
{
	if (this -> string) return this -> string . value () . data ();
	else return nullptr;
}
