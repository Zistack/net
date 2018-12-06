void
T::remove (Cancellable::T & cancellable)
{
	std::unique_lock<decltype (this->m)> (this->m);

	this->members.erase (&cancellable);
}
