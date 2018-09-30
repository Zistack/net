T::~T ()
{
	if (this->exception_store)
		this->exception_store->tryStore ([&]() { this->signal.clear (); });
	else
		this->signal.clear ();
}
