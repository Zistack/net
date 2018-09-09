void
T::stop ()
{
	this->signal->send ();
}
