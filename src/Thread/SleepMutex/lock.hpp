void
T::lock ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	while (this->locked) this->c.wait (lock);

	this->locked = true;
}
