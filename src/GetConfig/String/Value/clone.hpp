std::unique_ptr<Member::Value::T>
T::clone () const
{
	return std::make_unique<T> (*this);
}
