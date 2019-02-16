std::unique_ptr<MemberType::T>
T::clone () const
{
	return std::make_unique<T> (*this);
}
