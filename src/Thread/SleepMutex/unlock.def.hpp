void
T::unlock ()
{
	std::unique_lock lock (this -> m);

	this -> locked = false;

	this -> c . notify_one ();
}
