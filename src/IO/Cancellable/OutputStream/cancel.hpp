void
T::cancel ()
{
	this -> signal -> notify ();
}
