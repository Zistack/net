void
T::validate (const Member::Value::T & value) const
{
	const ValueType & section = dynamic_cast<const ValueType &> (value);

	section.validate ();
}
