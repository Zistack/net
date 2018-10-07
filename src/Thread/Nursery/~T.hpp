T::~T () noexcept (false)
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	while (!this->threads.empty ()) this->c.wait (lock);

	if (this->external_store)
	{
		this->external_store->tryStore (
		    [this]() { this->exception_store.poll (); });
	}
	else
		this->exception_store.poll ();
}
