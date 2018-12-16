std::unique_ptr<Host::T>
T::clone () const
{
	return std::make_unique<T> (*this);
}
