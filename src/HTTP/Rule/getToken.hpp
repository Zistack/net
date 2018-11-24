std::string
getToken (IO::Interface::PeekableInputStream::T & input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getToken\n";

	try
	{
		std::string token;

		while (IO::Util::test (input_stream, Class::token))
		{
			token.push_back (input_stream.get ());
		}

		if (!token.empty ()) return token;

		throw Failure::Error::T (
		    IO::Message::unexpectedCharacter (input_stream.peek ()));
	}
	catch (IO::EOF::T e)
	{
		if (!token.empty ()) return token;

		throw Failure::Error::T (
		    message_prefix + IO::Message::unexpectedEOF ());
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
