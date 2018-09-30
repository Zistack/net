void
T::unlock ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	this->locked = false;

	this->c.notify_one ();
}
