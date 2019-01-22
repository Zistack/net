void
T::cancel ()
{
	std::unique_lock<decltype (this->nursery_mutex)> nursery_lock (
	    this->nursery_mutex);

	if (this->nursery) this->nursery->cancel ();
}
