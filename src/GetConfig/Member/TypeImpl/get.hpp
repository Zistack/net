template <typename TypeType, typename ValueType>
const typename ValueType::InterfaceType &
T<TypeType, ValueType>::get (const ValueType & value) const
{
	return value.get ();
}
