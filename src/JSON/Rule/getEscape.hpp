char32_t
getEscape (IO::Interface::InputStream::T * input_stream)
{
	const std::string message_prefix = "JSON::Rule::getEscape\n";

	char32_t rune = 0;
	char16_t first = 0;

	try
	{
		first = getCodePoint (input_stream);

		if ((first & 0xFC00) == 0xD800)
		{
			rune |= (char32_t) (first & 0x03FF);

			IO::Util::expect (input_stream, "\\u");

			char16_t second = getCodePoint (input_stream);

			if ((second & 0xFC00) != 0xDC00)
			{
				throw ParsingError::T (IO::Message::unexpectedCharacter (
				    second, "a high surrogate code point"));
			}

			rune |= ((char32_t) (second & 0x03FF)) << 10;
		}
		else if ((first & 0xFC00) == 0xDC00)
		{
			throw ParsingError::T (IO::Message::unexpectedCharacter (
			    first, "a code point in the basic multilingual plane"));
		}
		else
			rune = first;

		if ((rune & 0xFC00) == 0xD800 || (rune & 0xFC00) == 0xDC00 ||
		    rune > 0x10FFFF)
		{
			throw ParsingError::T (IO::Message::unexpectedCharacter (
			    rune, "a valid UTF code point"));
		}

		return rune;
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
