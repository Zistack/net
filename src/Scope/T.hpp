template <class Scopable>
T<Scopable>::T () : scopable (nullptr)
{
}

template <class Scopable>
T<Scopable>::T (Scopable & scopable) : scopable (&scopable)
{
	scopable.open ();
}

template <class Scopable>
T<Scopable>::T (T && other) : scopable (other.scopable)
{
	other.scopable = nullptr;
}
