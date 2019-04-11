template <typename InputStream>
char32_t
getEscape (InputStream && input_stream)
{
	char32_t rune = 0;
	char16_t first = 0;

	first = getCodePoint (std::forward <InputStream> (input_stream));

	if ((first & 0xFC00) == 0xD800)
	{
		rune |= (char32_t) (first & 0x03FF);

		IO::Util::expect (std::forward <InputStream> (input_stream), "\\u");

		char16_t second = getCodePoint
		(
			std::forward <InputStream> (input_stream)
		);

		if ((second & 0xFC00) != 0xDC00)
		{
			throw Failure::EncodingError::T
			(
				IO::Message::unexpectedCharacter
				(
					second,
					"a high surrogate code point"
				)
			);
		}

		rune |= ((char32_t) (second & 0x03FF)) << 10;
	}
	else if ((first & 0xFC00) == 0xDC00)
	{
		throw Failure::EncodingError::T
		(
			IO::Message::unexpectedCharacter
			(
				first,
				"a code point in the basic multilingual plane"
			)
		);
	}
	else rune = first;

	if ((rune & 0xFC00) == 0xD800 || (rune & 0xFC00) == 0xDC00 || rune > 0x10FFFF)
	{
		throw Failure::EncodingError::T
		(
			IO::Message::unexpectedCharacter
			(
				rune,
				"a valid UTF code point"
			)
		);
	}

	return rune;
}
