template <class Scopable>
T<Scopable>::T () : scopable (nullptr)
{
}

template <class Scopable>
T<Scopable>::T (Scopable & scopable) : scopable (&scopable)
{
	fprintf (stderr, "Opening %p from constructor\n", this->scopable);
	scopable.open ();
}

template <class Scopable>
T<Scopable>::T (T && other) : scopable (other.scopable)
{
	fprintf (stderr, "Moving %p from constructor\n", this->scopable);
	other.scopable = nullptr;
}
