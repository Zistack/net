template <class Scopable>
T<Scopable>::T () : scopable (nullptr), exception_store (nullptr)
{
}

template <class Scopable>
T<Scopable>::T (Scopable & scopable,
    Failure::ExceptionStore::T & exception_store) :
    scopable (&scopable),
    exception_store (&exception_store)
{
	scopable.open ();
}

template <class Scopable>
T<Scopable>::T (T && other) :
    scopable (other.scopable),
    exception_store (other.exception_store)
{
	other.scopable = nullptr;
	other.exception_store = nullptr;
}
