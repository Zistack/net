template <typename Scopable>
T<Scopable>::T () : scopable (nullptr)
{
}

template <typename Scopable>
template <typename... Arguments>
T<Scopable>::T (Scopable & scopable, Arguments &&... arguments) :
    scopable (&scopable)
{
	scopable.open (std::forward<Arguments> (arguments)...);
}

template <typename Scopable>
T<Scopable>::T (T && other) : scopable (other.scopable)
{
	other.scopable = nullptr;
}
