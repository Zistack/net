T::T (IO::PeekableInputStream::T & input_stream)
{
	while (!IO::Util::test (input_stream, '\r'))
	{
		std::string field_name = Rule::getToken (input_stream);
		for (char & c : field_name) c = (char) std::tolower (c);

		IO::Util::expect (input_stream, ':');

		Util::skipWhitespace (input_stream);

		std::string field_value;

		while (!IO::Util::test (input_stream, '\r'))
		{
			std::string value_part = Rule::getVChars (input_stream);

			if (!field_value.empty ()) field_value.push_back (' ');
			field_value.append (value_part);

			Util::skipWhitespace (input_stream);
		}

		IO::Util::expect (input_stream, "\r\n");

		this->map.insert ({field_value, field_name});
	}
}

template <class Iterable, typename>
T::T (const Iterable & iterable) : map (iterable.begin (), iterable.end ())
{
}
