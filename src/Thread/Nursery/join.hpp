void
T::join ()
{
	std::unique_lock<decltype(this->mutex)> lock (this->mutex);

	while (!this->threads.empty ()) this->condition_variable.wait (lock);
}
