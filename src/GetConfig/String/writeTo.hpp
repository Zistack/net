void
T::writeTo (const MemberValue::T & member,
    IO::Interface::OutputStream::T & output_stream,
    size_t indentation) const
{
	const ValueType & string = dynamic_cast<const ValueType &> (member);

	string.writeTo (output_stream, indentation);
}
