void
T::cancel ()
{
	std::unique_lock<decltype (this->m)> (this->m);

	for (Cancellable::T * cancellable : this->members)
	{
		cancellable->cancel ();
	}
}
