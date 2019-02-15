void
T::writeTo (const MemberValue::T & member,
    IO::Interface::OutputStream::T & output_stream,
    size_t indentation) const
{
	const ValueType & string_member = dynamic_cast<const ValueType &> (member);

	output_stream.put ('"');

	for (char c : string_member.value)
	{
		if (c == '"')
		{
			output_stream.print ("\\\"");
		}
		else
		{
			output_stream.put (c);
		}
	}

	output_stream.put ('"');
}
