void
T::writeTo (const Member::Value::T & value,
    IO::Interface::OutputStream::T & output_stream,
    size_t indentation) const
{
	const ValueType & uint = dynamic_cast<const ValueType &> (value);

	uint.writeTo (output_stream, indentation);
}
