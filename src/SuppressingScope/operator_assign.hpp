template <class Scopable>
T<Scopable> &
T<Scopable>::operator= (T && other)
{
	if (this->scopable)
	{
		this->exception_store->tryStore (
		    [this]() { this->scopable->close (); });
	}

	this->scopable = other.scopable;
	this->exception_store = other.exception_store;
	other.scopable = nullptr;
	other.exception_store = nullptr;

	return *this;
}
