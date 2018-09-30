void
T::clear ()
{
	std::unique_lock<T> lock (*this);

	this->state = false;

	if (this->clearCallback) this->clearCallback ();
}
