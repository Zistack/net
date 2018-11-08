void
T::join ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	while (!this->threads.empty ()) this->c.wait (lock);

	if (this->internal_store) this->internal_store->poll ();
}
