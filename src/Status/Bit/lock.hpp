void
T::lock ()
{
	this->sleep_lock.lock ();
}
