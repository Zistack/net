template <class Scopable>
T<Scopable>::~T ()
{
	if (this->scopable)
	{
		fprintf (stderr, "Closing scopable object: %p\n", this->scopable);
		this->exception_store->tryStore (
		    [this]() { this->scopable->close (); });
	}
}
