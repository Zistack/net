void
T::set ()
{
	std::unique_lock<T> lock (*this);

	this->state = true;

	this->setCallback ();
}
