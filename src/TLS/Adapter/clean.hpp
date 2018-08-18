void
T::clean ()
{
	this->shutdown_signal->send ();
	nursery.join ();
}
