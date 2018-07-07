std::string
getExponent (IO::Interface::PeekableInputStream::T * input_stream)
{
	const std::string message_prefix = "JSON::Rule::getExponent\n";

	std::string exponent;

	try
	{
		char c = input_stream->peek ();

		if (c == '+' || c == '-')
		{
			exponent.push_back (input_stream->get ());
		}
		else
			exponent.push_back ('+');

		while ((c = IO::Util::test (input_stream, Class::digit)))
		{
			exponent.push_back (input_stream->get ());
		}

		if (exponent.empty ())
		{
			throw ParsingError::T (
			    IO::Message::unexpectedCharacter (c, "'-' or digit"));
		}
		if (exponent[0] == '-' && exponent.size () == 1)
		{
			throw ParsingError::T (
			    IO::Message::unexpectedCharacter (c, "digit"));
		}
		else
			return exponent;
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
	catch (const IO::EOF::T & e)
	{
		if (exponent.empty () || (exponent[0] == '-' && exponent.size () == 1))
		{
			throw ParsingError::T (
			    message_prefix + IO::Message::unexpectedEOF ());
		}
		else
			return exponent;
	}
}
