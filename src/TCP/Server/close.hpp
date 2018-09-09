void
T::close ()
{
	this->signal->send ();
}
