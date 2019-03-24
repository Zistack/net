template <class Lockable>
void
T <Lockable>::close ()
{
	std::unique_lock lock (this -> lockable);

	this -> state = false;
}
