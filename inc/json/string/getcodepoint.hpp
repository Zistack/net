Error::T
getCodePoint (std::istream * json_stream, uint16_t * cp)
{
	std::char_traits<char>::int_type c;
	uint16_t n;

	int i;
	for (i = 3; i >= 0; --i)
	{
		c = json_stream->get ();

		if (eof (c)) return Error::UNEXPECTED_EOF;

		if (c >= '0' && c <= '9')
			n = (uint16_t) c - '0';
		else if (c >= 'A' && c <= 'F')
			n = (uint16_t) c - 'A';
		else if (c >= 'a' && c <= 'f')
			n = (uint16_t) c - 'a';
		else
			return Error::INVALID_CHARACTER;

		*cp |= n << (i * 4);
	}

	return Error::NONE;
}
