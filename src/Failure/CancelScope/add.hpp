void
T::add (Cancellable::T & cancellable)
{
	std::unique_lock<decltype (this->m)> (this->m);

	this->members.insert (&cancellable);
}
