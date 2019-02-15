std::unique_ptr<MemberValue::T>
T::readFrom (IO::Interface::PeekableInputStream::T & input_stream) const
{
	std::string value;

	IO::Util::expect (input_stream, '"');

	while (true)
	{
		char c = input_stream.get ();

		if (c == '\\')
		{
			value.push_back (input_stream.get ());
		}
		else if (c == '"')
		{
			break;
		}
		else
		{
			value.push_back (c);
		}
	}

	return std::make_unique<ValueType> (value);
}
