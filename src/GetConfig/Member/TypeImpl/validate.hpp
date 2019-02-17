template <typename TypeType, typename ValueType>
void
T<TypeType, ValueType>::validate (const Member::Value::T & value) const
{
	const ValueType & typed_value = dynamic_cast<const ValueType &> (value);

	typed_value.validate ();
}
