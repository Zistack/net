template <class Scopable>
T<Scopable>::~T ()
{
	if (this->scopable) this->scopable->close ();
}
