template <class Scopable>
T<Scopable> &
T<Scopable>::operator= (T && other)
{
	if (this->scopable) this->scopable->close ();

	this->scopable = other.scopable;
	other.scopable = nullptr;

	return *this;
}
