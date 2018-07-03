template <typename Base, typename Derived>
Base *
T<Base, Derived>::clone () const
{
	return new Derived (*this);
}
