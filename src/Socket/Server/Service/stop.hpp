void
T::stop ()
{
	this->shutdown_signal.send ();
}
