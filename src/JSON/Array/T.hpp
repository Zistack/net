T::T (IO::Interface::PeekableInputStream::T & input_stream)
{
	const std::string message_prefix = "JSON::Array::T\n";

	try
	{
		IO::Util::expect (input_stream, '[');

		Util::skipWhitespace (input_stream);
		if (IO::Util::test (input_stream, ']'))
		{
			input_stream.get ();
			return;
		}

		while (true)
		{
			members.push_back (read (input_stream));

			Util::skipWhitespace (input_stream);
			char c = input_stream.get ();

			if (c == ']') return;

			if (c == ',') continue;

			throw Failure::Error::T (
			    IO::Message::unexpectedCharacter (c, "']' or ','"));
		}
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
	catch (const Failure::EndOfResource::T & e)
	{
		throw Failure::Error::T (
		    message_prefix + IO::Message::unexpectedEOF ());
	}
}

template <class Iterable>
T::T (const Iterable & members) : members (members.begin (), members.end ())
{
}
