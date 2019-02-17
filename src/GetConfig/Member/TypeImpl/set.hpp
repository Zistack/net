template <typename TypeType, typename ValueType>
std::unique_ptr<ValueType>
T<TypeType, ValueType>::set (
    const typename ValueType::InterfaceType & value) const
{
	return std::make_unique<ValueType> (value);
}
