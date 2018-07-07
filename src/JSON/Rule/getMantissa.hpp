std::string
getMantissa (IO::Interface::PeekableInputStream::T * input_stream)
{
	const std::string message_prefix = "JSON::Rule::getMantissa\n";

	std::string mantissa;

	try
	{
		while (Class::digit (input_stream->peek ()))
		{
			mantissa.push_back (input_stream->get ());
		}

		if (mantissa.empty ())
		{
			throw ParsingError::T (IO::Message::unexpectedCharacter (
			    input_stream->peek (), "digit"));
		}
		else
			return mantissa;
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
	catch (const IO::EOF::T & e)
	{
		if (mantissa.empty ())
		{
			throw ParsingError::T (
			    message_prefix + IO::Message::unexpectedEOF ());
		}
		else
			return mantissa;
	}
}
