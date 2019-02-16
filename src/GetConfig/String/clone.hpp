std::unique_ptr<Member::T>
T::clone () const
{
	return std::make_unique<T> (*this);
}
