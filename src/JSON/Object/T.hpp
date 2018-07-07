T::T (InputStream::T * json_input_stream)
{
	const std::string message_prefix = "JSON::Object::T\n";

	try
	{
		IO::Interface::PeekableInputStream::T * input_stream =
		    json_input_stream->input_stream;

		Util::skipWhitespace (input_stream);
		IO::Util::expect (input_stream, '{');

		Util::skipWhitespace (input_stream);
		if (IO::Util::test (input_stream, '}'))
		{
			input_stream->get ();
			return;
		}

		while (true)
		{
			String::T * json_string = new String::T (input_stream);
			std::string key = json_string->value;
			delete json_string;

			Util::skipWhitespace (input_stream);
			IO::Util::expect (input_stream, ':');

			Value::T * json_value = json_input_stream->get ();

			members.insert ({key, json_value});

			Util::skipWhitespace (input_stream);
			char c = input_stream->get ();

			if (c == '}') return;

			if (c == ',') continue;

			throw ParsingError::T (
			    IO::Message::unexpectedCharacter (c, "'}' or ','"));
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
	catch (IO::EOF::T & e)
	{
		throw ParsingError::T (message_prefix + IO::Message::unexpectedEOF ());
	}
}

T::T (std::unordered_map<std::string, Value::T *> members) : members (members)
{
}
