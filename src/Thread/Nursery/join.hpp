void
T::join ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	while (!this->threads.empty ()) this->c.wait (lock);
}
