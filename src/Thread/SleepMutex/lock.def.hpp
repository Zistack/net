void
T::lock ()
{
	std::unique_lock lock (this -> m);

	while (this -> locked) this -> c . wait (lock);

	this -> locked = true;
}
