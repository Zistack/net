template <typename TypeType, typename ValueType>
std::unique_ptr<Type::T>
T<TypeType, ValueType>::clone () const
{
	return std::make_unique<TypeType> (*this);
}
