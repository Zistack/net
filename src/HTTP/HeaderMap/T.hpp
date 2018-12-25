T::T (IO::PeekableInputStream::T & input_stream)
{
	while (!IO::Util::test (input_stream, '\r'))
	{
		std::string field_name = normalize (Rule::getToken (input_stream));

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

		this->map.insert ({field_name, field_value});
	}
}

template <class Iterable, typename>
T::T (const Iterable & iterable) : map (iterable.begin (), iterable.end ())
{
}
