template <typename ValueType>
std::unique_ptr<Value::T>
T<ValueType>::clone () const
{
	return std::make_unique<ValueType> (*this);
}
