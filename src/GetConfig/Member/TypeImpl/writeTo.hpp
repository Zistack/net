template <typename TypeType, typename ValueType>
void
T<TypeType, ValueType>::writeTo (const Member::Value::T & value,
    IO::Interface::OutputStream::T & output_stream,
    size_t indentation) const
{
	const ValueType & typed_value = dynamic_cast<const ValueType &> (value);

	typed_value.writeTo (output_stream, indentation);
}
