std::unique_ptr<GetConfig::Member::Value::T>
T::clone () const
{
	return std::make_unique<T> (*this);
}
