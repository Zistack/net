void
T::lock ()
{
	std::unique_lock<std::mutex> lock (this->mutex);
	while (this->locked)
	{
		this->condition_variable.wait (lock);
	}
	this->locked = true;
}
