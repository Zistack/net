void
T::writeTo (const Member::Value::T & value,
    IO::Interface::OutputStream::T & output_stream,
    size_t indentation) const
{
	const ValueType & string = dynamic_cast<const ValueType &> (value);

	string.writeTo (output_stream, indentation);
}
