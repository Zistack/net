std::unique_ptr<MemberValue::T>
T::clone () const
{
	return std::make_unique<T> (*this);
}
