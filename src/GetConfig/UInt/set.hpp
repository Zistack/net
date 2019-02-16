std::unique_ptr<T::ValueType>
T::set (const ValueType::InterfaceType & value) const
{
	return std::make_unique<ValueType> (value);
}
