Error::T
decode (std::istream * json_stream, std::string * value)
{
	uint16_t first = 0;
	uint32_t rune = 0;

	Error::T ret;

	if ((ret = getCodePoint (json_stream, &first))) return ret;

	if ((first & 0xFC00) == 0xD800)
	{
		rune |= (uint32_t) (first & 0x03FF);

		uint16_t second = 0;

		std::char_traits<char>::int_type c = json_stream->get ();

		if (eof (c)) return Error::UNEXPECTED_EOF;
		if (c != '\\') return Error::INVALID_CHARACTER;

		c = json_stream->get ();

		if (eof (c)) return Error::UNEXPECTED_EOF;
		if (c != 'u') return Error::INVALID_CHARACTER;

		if ((ret = getCodePoint (json_stream, &second))) return ret;

		if ((second & 0xFC00) != 0xDC00) return Error::INVALID_CODE_POINT;

		rune |= ((uint32_t) (second & 0x03FF)) << 10;
	}
	else if ((first & 0xFC00) == 0xDC00)
	{
		return Error::INVALID_CODE_POINT;
	}
	else
		rune = first;

	if ((rune & 0xFC00) == 0xD800 || (rune & 0xFC00) == 0xDC00 ||
	    rune > 0x10FFFF)
	{
		return Error::INVALID_CODE_POINT;
	}

	// In theory, spitting stuff out into a stream can fail too.  We should
	// account for that.

	if (rune < 0x0080)
	{
		value->push_back ((char) rune);
	}
	else if (rune < 0x0800)
	{
		value->push_back ((char) (0b11000000 | ((rune >> 6) & 0b00011111)));
		value->push_back ((char) (0b10000000 | (rune & 0b00111111)));
	}
	else if (rune < 0x10000)
	{
		value->push_back ((char) (0b11100000 | ((rune >> 12) & 0b00001111)));
		value->push_back ((char) (0b10000000 | ((rune >> 6) & 0b00111111)));
		value->push_back ((char) (0b10000000 | (rune & 0b00111111)));
	}
	else
	{
		value->push_back ((char) (0b11110000 | ((rune >> 18) & 0b00000111)));
		value->push_back ((char) (0b10000000 | ((rune >> 12) & 0b00111111)));
		value->push_back ((char) (0b10000000 | ((rune >> 6) & 0b00111111)));
		value->push_back ((char) (0b10000000 | (rune & 0b00111111)));
	}

	return Error::NONE;
}
