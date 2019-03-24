template <class Lockable>
void
T <Lockable>::open ()
{
	std::unique_lock lock (this -> lockable);

	this -> state = true;
}
