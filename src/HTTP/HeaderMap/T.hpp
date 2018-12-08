T::T (IO::PeekableInputStream::T & input_stream)
{
	const char message_prefix = "HTTP::HeaderMap::T::T\n";

	try
	{
		while (!IO::Util::test (input_stream, '\r'))
		{
			std::string field_name = Rule::getToken ();
			for (char & c : field_name) c = std::tolower (c);

			IO::Util::expect (input_stream, ':');

			Util::skipWhitespace (input_stream);

			std::string field_value;

			while (!IO::Util::test (input_stream, '\r'))
			{
				std::string value_part = Rule::getVChars (input_stream);

				if (!field_value.empty ()) field_value.push_back (' ');
				field_value.append (value_part);

				Util::skipWhitespace (input_stream)
			}

			IO::Util::expect (input_stream, "\r\n");

			this->map.insert ({field_value, field_name});
		}
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}

template <class Iterable, typename>
T::T (const Iterable & iterable) : map (iterable.begin (), iterable.end ())
{
}
