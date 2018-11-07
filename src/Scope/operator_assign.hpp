template <class Scopable>
T<Scopable> &
T<Scopable>::operator= (T && other)
{
	if (this->scopable)
	{
		fprintf (stderr, "Closing %p from assignment\n", this->scopable);
		this->scopable->close ();
	}

	fprintf (stderr, "Moving %p from assignment\n", other.scopable);
	this->scopable = other.scopable;
	other.scopable = nullptr;

	return *this;
}
