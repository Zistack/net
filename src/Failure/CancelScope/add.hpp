bool
T::add (Cancellable::T & cancellable)
{
	std::unique_lock<decltype (this->m)> (this->m);

	if (this->cancelled) return true;

	this->members.insert (&cancellable);

	return false;
}
