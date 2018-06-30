std::string
getToken (IO::Interface::PeekableInputStream::T <char> * filtered_input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getToken\n";

	try
	{
		Util::skipWhitespace (filtered_input_stream);

		std::string token;

		while (IO::Util::test (filtered_input_stream, Class::token))
		{
			token . push_back (filtered_input_stream -> get ());
		}

		if (! token.empty ()) return token;

		throw EncodingError::T (
			IO::Message::unexpectedCharacter (filtered_input_stream -> peek ())
		);
	}
	catch (IO::EOF::T e)
	{
		if (! token.empty ()) return token;

		throw IO::EncodingError::T (message_prefix + IO::Message::unexpectedEOF ());
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
