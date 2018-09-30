T::~T ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	while (!this->threads.empty ()) this->c.wait (lock);

	this->exception_store.poll ();
}
