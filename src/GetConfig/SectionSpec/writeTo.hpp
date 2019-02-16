void
T::writeTo (const MemberValue::T & value,
    IO::Interface::OutputStream::T & output_stream,
    size_t indentation) const
{
	const ValueType & section = dynamic_cast<const ValueType &> (value);

	section.writeTo (output_stream, indentation);
}
