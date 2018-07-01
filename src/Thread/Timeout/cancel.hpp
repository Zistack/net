void
T::cancel ()
{
	this->mutex->lock ();

	if (!*this->cancelled)
	{
		*this->cancelled = true;
		this->mutex->unlock ();
		return;
	}

	this->mutex->unlock ();

	delete mutex;
	delete cancelled;
}
