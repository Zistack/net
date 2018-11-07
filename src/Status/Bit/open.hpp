template <class Lockable>
void
T<Lockable>::open ()
{
	std::unique_lock<Lockable> lock (this->lockable);

	this->state = true;
}
