template <class Scopable>
T<Scopable>::~T ()
{
	if (this->scopable)
	{
		fprintf (stderr, "Closing %p from destructor\n", this->scopable);
		this->scopable->close ();
	}
}
