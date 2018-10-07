T::T (IO::Interface::PeekableInputStream::T * input_stream)
{
	const std::string message_prefix = "JSON::Object::T\n";

	try
	{
		IO::Util::expect (input_stream, '{');

		Util::skipWhitespace (input_stream);
		if (IO::Util::test (input_stream, '}'))
		{
			input_stream->get ();
			return;
		}

		while (true)
		{
			Util::skipWhitespace (input_stream);

			String::T * json_string = new String::T (input_stream);
			std::string key = json_string->value;
			delete json_string;

			Util::skipWhitespace (input_stream);
			IO::Util::expect (input_stream, ':');

			Value::T * json_value = read (input_stream);

			members.insert ({key, json_value});

			Util::skipWhitespace (input_stream);
			char c = input_stream->get ();

			if (c == '}') return;

			if (c == ',') continue;

			throw Failure::Error::T (
			    IO::Message::unexpectedCharacter (c, "'}' or ','"));
		}
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
	catch (IO::EOF::T & e)
	{
		throw Failure::Error::T (
		    message_prefix + IO::Message::unexpectedEOF ());
	}
}

template <class Iterable>
T::T (const Iterable & members) : members (members.begin (), members.end ())
{
}
