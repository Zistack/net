void
T::cancel ()
{
	if (this->cancelled.load ()) return;
	this->signal.send ();
}
